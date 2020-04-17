#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct node{
  int val;
  node *left, *right;
  node(int val): val(val), left(NULL), right(NULL){}
};

//time: O(h)
bool search(node *root, int x){
  if(!root)
    return false;
  else if(root->val==x)
    return true;
  else if(root->val>x)
    return search(root->left, x);
  else
    return search(root->right, x);
}

node* LCA(node* root, int x, int y){
  if(!root)
    return NULL;
  queue<node*> q;
  q.push(root);
  node *ans;
  int less = min(x,y);
  int great = max(x,y);
  while(!q.empty()){
    ans=q.front();
    q.pop();
    if((search(ans->left, less) && search(ans->right, great))
     ||(ans->val==less && search(ans->right, great))
     ||(ans->val==great && search(ans->left,less)) )
      return ans;
    if(ans->left)
      q.push(ans->left);
    if(ans->right)
      q.push(ans->right);
  }
  return NULL;
}

int main(){
  node *root = new node(5);
  root->left = new node(3);
  root->right = new node(6);
  (root->left)->left = new node(1);
  (root->left)->right = new node(4);

  cout << LCA(NULL,1,6) << endl;
}