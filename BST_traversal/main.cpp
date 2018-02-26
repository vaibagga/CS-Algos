#include <iostream>

using namespace std;

/*
a node data type consists of
data
left pointer to left child
right poiter to right child
*/

struct node{
    int data;
    node *left;
    node *right;
};

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
void inorder(node *root){
    if (root == NULL){
        return;
    }
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);

}
void postorder(node *root){
    if (root == NULL){
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}
void preorder(node *root){
    if (root == NULL){
        return;
    }
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
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
    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    return 0;
}
