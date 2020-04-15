#include<iostream>
#include<queue>

using namespace std;

//Time: O(n)
//Space: O(n) <-- improve!

void urlify(string &s, int size){
  queue<char> q;
  int i=0;
  for(; i<size; i++){
    if(s[i]==' '){
      q.push('%');
      q.push('2');
      q.push('0');
    }
    else{
      q.push(s[i]);
    }
    s[i]=q.front();
    q.pop();
  }
  while(!q.empty()){
    s[i++]=q.front();
    q.pop();
  }
}

int main(){

  string s = "Mr John Smith    ";
  int size = 13;
  urlify(s, size);
  cout << s << endl;

  return 0;
}
