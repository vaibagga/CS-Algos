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
/*
deletion function takes the root node of the
tree and the data to be deleted from the tree,
searches for data in the tree, deletes it
from the tree, and returns the root pointer
*/

node *minimum_ptr(node *root){
    while (root -> left != NULL){
        root = root -> left;
    }
    return root;
}
node* deletion(node *root,int search_element){
    if (root == NULL){
        return root;
    }
    else if (root -> data == search_element){
        //term found
        if (root -> left == NULL && root -> right == NULL){ //no child
            delete root; //memory deleted
            root = NULL;
            return root;
        }
        else if (root -> left == NULL){ // only right child
            node *temp = root;
            root = root -> right;
        }
        else if (root -> right == NULL){ // only left child
            node *temp = root;
            root = root -> left;
        }
        else{ //both children present
            node *temp = minimum_ptr(root -> right);
            root -> data = temp -> data;
            root -> right = deletion(root -> right, temp -> data);
        }

        return root;
    }
    else if (root -> data > search_element){
        root -> left = deletion(root -> left, search_element);
    }
    else{
        root -> right = deletion(root -> right, search_element);
    }
}

void Inorder(node *root) {
	if(root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	cout << root -> data << " ";  //Print data
	Inorder(root->right);      // Visit right subtree
}
int main()
{
    node *root = NULL;
    int numTerm,deletion_element;
    cout << "Enter the number of terms to be inserted in the search tree: ";
    cin >> numTerm;
    cout << "Enter the terms to be inserted in the binary search tree: ";
    while(numTerm--){
        int term;
        cin >> term;
        root = insertion(root,term);
    }
    cout << "Enter the element to be deleted: ";
    cin >> deletion_element;
    root = deletion(root,deletion_element);
    cout << "Inorder: ";
    Inorder(root);
    return 0;
}
