#include<iostream>
#include<set>
#include <vector>

using namespace std;

bool isValid(string words, set<string> validwords){
  vector<bool> dp(words.size()+1, false);
  dp[0]=true;
  for(int i=0; i<words.size(); i++){
    for(int j=0; j<=i; j++){
      if(dp[j] && validwords.find(words.substr(j,i-j+1))!=validwords.end())
        dp[i+1]=true;
    }
  }
  return dp[words.size()];
}


int main(){
  cout << isValid("samsungandmangok", {"mobile", "samsung", "sam", "sung", "man", 
                  "mango", "icecream", "and", "go", "i", "like", "ice", "cream" }) << endl;
  return 0;
}
