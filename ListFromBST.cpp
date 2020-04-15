#include<iostream>
#include <list>
#include <queue>
#include<cmath>

using namespace std;

struct listNode{
  int val;
  listNode *next;
  listNode(int val): val(val), next(NULL){}
};

struct treeNode{
  int val;
  treeNode *left, *right;
  treeNode(int val): val(val), left(NULL), right(NULL){}
};

vector<listNode*> listFromTree(treeNode *treeroot){
  vector<listNode*> ans;
  if(treeroot==NULL) 
    return ans;

  int depth = 0;
  queue<treeNode*> q;
  q.push(treeroot);
  int n=1;
  listNode *listroot= new listNode(treeroot->val);
  ans.push_back(listroot);
  listNode *ant=listroot;

  do{
    treeNode *top = q.front();
    q.pop();
    if (top->left != NULL){//left ins't null then 
      q.push(top->left);//push left
      if(n == pow(2,depth)){
        n=0;
        depth++;
        listNode *root = new listNode(top->left->val);
        ans.push_back(root);
        ant = root;
      }
      else{
        ant->next = new listNode(top->left->val);
        ant = ant->next;
      }
      n++;
    }
    if(top->right != NULL){ //right ins't null then 
      q.push(top->right);//push right
      if(n==pow(2,depth)){ 
        n=0;
        depth++;
        listNode *root = new listNode(top->right->val);
        ans.push_back(root);
        ant = root;
      }
      else{
        ant->next = new listNode(top->right->val);
        ant = ant->next;
      }
      n++;
    }
  }while (!q.empty()); //queue isn't empty
  return ans;
}

int main(){

  treeNode *root = new treeNode(5);
  root->left = new treeNode(3);
  root->right = new treeNode(6);
  (root->left)->left = new treeNode(1);
  (root->left)->right = new treeNode(4);

  vector<listNode*> l =  listFromTree(root);
  cout << l.size() << endl;

  for(int i=0; i<l.size(); i++){
    listNode* aux=l[i];
    do{
      cout << aux->val << " ";
    }while((aux=aux->next)!=NULL);
    cout << endl;
  }

  return 0;
}
