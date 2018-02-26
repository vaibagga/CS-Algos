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
to make sure program is working
correctly, bool_search searches for an
element in the BST and returns a boolean
to indicate whether it exists in the BST
*/

bool bin_search(node *root,int search_element){
    if (root == NULL){
        return false;
    }
    else if (root -> data == search_element){
        return true;
    }
    else if (root -> data > search_element){
        return bin_search(root -> left, search_element);
    }
    else{
        return bin_search(root -> right, search_element);
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
    //cout << root;
    //cout << root -> data;
    cout << "Enter the element to be searched: ";
    cin >> search_element;
    if (bin_search(root, search_element)==false){
        cout << "Element not found";
    }
    else{
        cout << "Element found";
    }
    return 0;
}
