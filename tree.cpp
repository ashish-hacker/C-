#include<bits/stdc++.h>

// Tree concepts and algorithms

using namespace std;

// create a tree
class tree{
    public:
    int val;
    tree* left = NULL;
    tree* right = NULL;
    tree(int data){ val = data; left = NULL; right = NULL;}
};
//inorder traversal
void inorder(tree* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

// pre-order traversal
void preorder(tree* root){
    if(root == NULL) return;

    cout<<root->val<<" ";
    inorder(root->left);
    inorder(root->right);
}


// post-order traversal
void postorder(tree* root){
    if(root == NULL) return;

    inorder(root->left);
    inorder(root->right);
    cout<<root->val<<" ";
}


int main(){
    tree* root = new tree(1);
    tree* left = new tree(2);
    tree* right = new tree(3);
    tree* left1 = new tree(4);
    tree* right1 = new tree(5);
    root->left = left;
    root->right = right;
    left->left = left1;
    left->right = right1;
    tree* left2 = new tree(6);
    tree* right2 = new tree(7);
    right->right = right2;
    right->left = left2;
    cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder traversal: ";
    preorder(root);
    cout<<"\n";
    cout<<"Postorder traversal: ";
    postorder(root);
    cout<<"\n";

    return 0;
}