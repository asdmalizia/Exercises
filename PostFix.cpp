#include<iostream>
#include<stack>
#include<map>

using namespace std;

void pushAns(stack<char> &operators, string &ans){
  ans += ' ';
  ans+= operators.top();
  operators.pop();
}

string infix2postfix(string exp){
  string ans;
  int i=-1;
  stack<char> operators;
  map<char, int> priority({{'+',0}, {'-', 0}, {'*', 1}, {'/', 1}});

  while((i=++i) < exp.size()){
    if(exp[i] >= '0' && exp[i] <= '9'){
      ans += exp[i];
      continue;
    }
    char op = exp[i];
    if(op == '('){
      operators.push(op);
    }
    else if(op == ')'){
      while(operators.top()!='(')
        pushAns(operators, ans);
      operators.pop();
    }
    else{
      while(!operators.empty() && operators.top()!='(' && priority[op]<=priority[operators.top()])
        pushAns(operators, ans);
      ans += ' ';
      operators.push(op);
    }
  }
  while(!operators.empty())
    pushAns(operators, ans);
  
  return ans;
}

int str2int(string s){
  int ans=0;
  for(int i=0; i<s.length(); i++){
    ans *= 10;
    ans += (int) s[i] - '0';
  }
  return ans;
}

float calculate(string postfix){
  int i=-1;
  string num;
  stack<float> operands;
  while((i=++i)<postfix.size()){
    if(postfix[i] >= '0' && postfix[i] <= '9'){
      num += postfix[i];
    }
    else if(postfix[i]==' ' && postfix[i-1] >= '0' && postfix[i-1] <= '9'){
      operands.push(str2int(num));
      num = "";
    }
    else if(postfix[i]!=' '){
      int op2 = operands.top();
      operands.pop();
      int op1 = operands.top();
      operands.pop();
      if(postfix[i]=='+') operands.push(op1+op2);
      else if(postfix[i]=='-') operands.push(op1-op2);
      else if(postfix[i]=='*') operands.push(op1*op2);
      else if(postfix[i]=='/') operands.push(op1/op2);
    }
  }
  return operands.top();
}

int main(){
  cout << infix2postfix("(3+4)*(1+2)") << endl;
  cout << calculate(infix2postfix("(3+4)*(1+2)/7")) << endl;
  return 0;
}
