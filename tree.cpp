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
int height(tree* root){
    if(root == NULL) return 0;

    return 1 + max(height(root->left), height(root->right));
}

void printKthLevel(tree* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 1){
        cout<<root->val<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}
void printAllLevels(tree* root){
    if(root == NULL) return;
    int h = height(root);

    for(int i = 0; i < h; i++){
        printKthLevel(root, i+1);
        cout<<endl;
    }
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
    //preorder(root);

    /*cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder traversal: ";
    preorder(root);
    cout<<"\n";
    cout<<"Postorder traversal: ";
    postorder(root);
    cout<<"\n";*/
    //cout<<endl<<height(root)<<endl;
    printAllLevels(root);
    cout<<endl;
    return 0;
}