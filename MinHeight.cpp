#include<iostream>
#include<vector>

using namespace std;

struct node{
  int val;
  node* left, *right;
  node(int val): val(val), left(NULL), right(NULL){}
};

node* recursive(vector<int> &arr, int begin, int end){
  if(begin==end)
    return new node(arr[begin]);
  int mid=(begin+end)/2;
  node* root = new node(arr[mid]);
  if(mid!=begin)
    root->left=recursive(arr, begin, mid-1);
  root->right=recursive(arr, mid+1, end);
  return root;
}

node* buildTree(vector<int> arr){
  if(arr.size()==0)
    return NULL;
  return recursive(arr, 0, arr.size()-1);
}

void inOrder(node* root){
  if(!root)
    return;
  inOrder(root->left);
  cout << root->val << " ";
  inOrder(root->right);
}

int main(){
  vector<int> arr({});
  node* root = buildTree(arr);
  inOrder(root);
  cout << endl;
  
  //function from RemoveBST.cpp
  //deleteNode(&root, 5);
  inOrder(root);
  cout << endl;
  
  return 0;
}
