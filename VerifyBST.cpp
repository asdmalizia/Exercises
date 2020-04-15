#include<iostream>

using namespace std;


struct node{
  int val;
  node *right, *left;
  node(int val): val(val), right(NULL), left(NULL){}
};

bool isBST(node *root){
  if(root->left==NULL && root->right==NULL){
    return true;
  }
  else if(root->right==NULL){
    return isBST(root->left) && root->val > (root->left)->val;
  }
  else if(root->left==NULL){
    return isBST(root->right) && root->val < (root->right)->val;
  }
  else{
    return isBST(root->right) && isBST(root->left)
        && (root->right)->val > root->val
        && (root->left)->val < root->val;
  } 
}


int main(){
  node *root = new node(6);
  root->left = new node(4);
  (root->left)->left = new node(5);
  (root->left)->right = new node(3);

  cout << isBST(root) << endl;
  return 0;
}
