#include <iostream>
#include <stack>

using namespace std;

class Queue{
public:
  stack<int> s1, s2;

  void swap(stack<int> &s1, stack<int> &s2){
    int n=s1.size();
    for(int i=0; i<n; i++){
      s2.push(s1.top());
      s1.pop();
    }
  }

  void push(int x){
    s1.push(x);
  }

  int pop(){
    //swap from s1 to s2
    swap(s1, s2);
    //pop from s2
    int ans = s2.top();
    s2.pop();
    //swap from s2 to s1
    swap(s2, s1);
    return ans;
  }

};


int main(){
  Queue q;

  for(int i=0; i<5; i++){
    q.push(i);
  }

  for(int i=0; i<5; i++){
    cout << q.pop() << endl;
  }

  return 0;
}
