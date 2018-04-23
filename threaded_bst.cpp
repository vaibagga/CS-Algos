#include <iostream>
#include <queue>

using namespace std;

/*
a node data type consists of
data
left pointer to left child
right poiter to right child
boolean thread to indicate whether node
is threaded, i.e. right pointer points
to inorder successor
*/

struct node{
    int data;
    node *left;
    node *right;
    bool thread;
};
queue <node*> pointer_queue;

/*
insertion function adds an element
to the binary search tree according
to its value
*/
node *create(int info){
    node *temp = new node();
    temp -> data = info;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}
node *insertion(node *root, int element){
    if (root == NULL){
        root = create(element);
    }
    else if (root -> data >= element){
        root -> left = insertion(root -> left, element);
    }
    else{
        root -> right = insertion(root -> right, element);
    }
    return root;
}
node *createThreaded(node *root){
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL){
        return root;
    }
    // Find inorder predecessor if it exists
    if (root->left != NULL){
        node* l = createThreaded(root->left);
        l->right = root;
        l->thread = true;
    }

    // If current node is rightmost child
    if (root->right == NULL)
        return root;

    // Recur for right subtree.
    return createThreaded(root->right);
}

void inorder(node *root){
    if (root == NULL){
        return;
    }
    inorder(root -> left);
    inorder(root -> right);
}
node *leftMost(node *root){
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

void inorder_threaded(node *root)
{
    if (root == NULL) return;

    // Find the leftmost node in Binary Tree
    node *cur = leftMost(root);

    while (cur != NULL){
        cout << cur->data << " ";
        if (cur->thread){
            cur = cur->right;
        }
        else //leftmost child in right subtree
            cur = leftMost(cur->right);
    }
}

int main()
{
    node *root = NULL;
    int numTerm,search_element;
    cout << "Enter the number of terms to be inserted in the search tree: ";
    cin >> numTerm;
    cout << "Enter the terms to be inserted in the binary search tree: ";
    while(numTerm--){
        int term;
        cin >> term;
        root = insertion(root,term);
    }
    cout << "\nInorder: ";
    createThreaded(root);
    inorder_threaded(root);
    return 0;
}
