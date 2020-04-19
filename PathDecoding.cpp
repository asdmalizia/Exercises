#include<iostream>
#include<stack>
#include<map>

using namespace std;

typedef long long ll;


void decode(string s, map<char, int> &count){
  int curr=1;
  stack<int> weight;
  for(int i=0; i<s.length(); i++){
    if(s[i]>='2' && s[i]<='9'){
      curr*=s[i]-'0';
      weight.push(s[i]-'0');
    }
    else if(s[i]==')'){
      curr/=weight.top();
      weight.pop();
    }
    else
      count[s[i]]+=curr;
  }
}

void move(string program, ll &x, ll &y){
  map<char, int> count;
  decode(program, count);
  x=1, y=1;
  x+=count['S']%(ll)1e+9;
  y+=count['E']%(ll)1e+9;
  x-=count['N']%(ll)1e+9;
  y-=count['W']%(ll)1e+9;
  if(x>1e+9)
    x%=(ll)1e+9;
  else if(x<1)
    x+= 1e+9;
  if(y>1e+9)
    y%=(ll)1e+9;
  else if(y<1)
    y+= 1e+9;
}

int main(){

  ll x=1, y=1;

  move("2(3(NW)2(W2(EE)W))", x, y);

  cout << y << " " << x << endl;
    
    return 0;
}