#include<iostream>
#include<set>
#include<stack>
#include<vector>

using namespace std;

struct node{
  string val;
  node *left;
  node *right;
  node(string s): val(s), left(NULL), right(NULL){}
};

/*
input: {3, 4, +, 1, 2, +, *}


          *
      /      \
    +         +
  /   \     /   \
3       4 1        2
*/

node* expressionTree(vector<string> expression){
  set<string> operators({"*","/","-","+"});
  stack<node*> operands;
  int i=1;
  operands.push(new node(expression[0]));
  do{
    if(operators.find(expression[i])==operators.end())
      operands.push(new node(expression[i]));
    else {
      node *root= new node(expression[i]);
      root->right=operands.top();
      operands.pop();
      root->left=operands.top();
      operands.pop();
      operands.push(root);
    }
    i++;
  }while(i<expression.size());
  return operands.top();
}

void inOrder(node* root){
  if(!root)
    return;
  inOrder(root->left);
  cout << root->val << " ";
  inOrder(root->right);
}


int main(){
  node *root = expressionTree({"1", "2", "+", "3", "4", "+", "*"});
  inOrder(root);
  cout << endl;
  return 0;
}
