#include<iostream>
#include<unordered_set>

using namespace std;

struct node{
  int val;
  node* next;
  node(int val): val(val), next(NULL){}
};

/*

1->2->3->4->5->NULL
1->2->3->4->5->2

visited = {1,2,3,4,5}

time: o(n)
space: o(n)

*/

bool detectAndRemoveLoop(node *root){
  unordered_set<int> visited;
  node *aux=root;
  while(aux->next){
    visited.insert(aux->val);
    if(visited.find((aux->next)->val) != visited.end()){
      aux->next=NULL;
      return true;
    }
    aux=aux->next;
  }
  return false;
}

int main(){
  node *root = new node(1);
  root->next = new node(2);
  (root->next)->next = new node(3);
  ((root->next)->next)->next = new node(5);
  //(((root->next)->next)->next)->next = root->next;

  cout << detectAndRemoveLoop(root) << endl;
  while(root){
    cout << root->val << endl;
    root = root->next;
  }

  return 0;
}
