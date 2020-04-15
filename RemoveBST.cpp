#include<iostream>

using namespace std;

struct node{
  int val;
  node *left, *right;
  node(int val): val(val), left(NULL), right(NULL){}
};

inline node* find(node* root, int val, node** parent){
  node* aux=root;
  *parent=NULL;
  while(aux!=NULL && aux->val!=val){
    *parent=aux;
    if(val<aux->val)
      aux=aux->left;
    else
      aux=aux->right;
  }
  return aux;
}

inline void remove(node* n, node** parent){
  if(!n->left && !n->right){
    if((*parent)->left && n->val==((*parent)->left)->val)
      (*parent)->left=NULL;
    else
      (*parent)->right=NULL;
    return;
  }
  if(n->right){
    *parent=n;
    node* aux=n->right;
    while(aux->left){
      *parent=aux;
      aux=aux->left;
    }
    n->val=aux->val;
    remove(aux, parent);
    return;
  }
  else if(n->left){
    *parent=n;
    node* aux=n->left;
    while(aux->right){
      *parent=aux;
      aux=aux->right;
    }
    n->val=aux->val;
    remove(aux, parent);
  }
}

inline void deleteNode(node** root, int val){
  node* parent;
  node *n = find(*root, val, &parent);
  if(!n)
    return;
  if(n==*root && !n->left && !n->right)
    *root=NULL;
  else
    remove(n, &parent);
}

int main(){
  node *root = new node(5);
  root->left = new node(3);
  root->right = new node(6);
  (root->left)->left = new node(1);
  (root->left)->right = new node(4);

  return 0;
}
