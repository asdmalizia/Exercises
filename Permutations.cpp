#include <iostream>
#include<vector>
#include<queue>

using namespace std;

struct treeNode{
  string word;
  vector<char> letters;
  treeNode(string w, vector<char> letter){
    word=w;
    letters=vector<char>(letter);
  } 
};

vector<string> permutations(string s){
  vector<char> letters;
  for(int i=0; i<s.length(); i++){
    letters.push_back(s[i]);
  }
  treeNode* treeRoot=new treeNode("", letters);
  queue<treeNode*> q;
  q.push(treeRoot);
  
  vector<string> ans;
  while(!q.empty()){
    treeNode* node=q.front();
    q.pop();
    if((node->word).length()==s.length())
      ans.push_back(node->word);
    for(int i=0; i<(node->letters).size(); i++){
      string word=node->word + (node->letters)[i];
      vector<char> childletters;
      for(int j=0; j<(node->letters).size(); j++){
        if(j!=i)
          childletters.push_back((node->letters)[j]);
      }
      treeNode* child= new treeNode(word, childletters);
      q.push(child);
    }
  }
  return ans;
}

void recursive(string s, int begin, vector<string> &ans){
  if(begin==s.length()-1){
    ans.push_back(s);
    return;
  }
  recursive(s, begin+1, ans);
  for(int i=begin+1; i<s.length(); i++){
    swap(s[i], s[begin]);
    recursive(s, begin+1, ans);
    swap(s[i], s[begin]);
  }
}

vector<string> rec_permutations(string s){
  vector<string> ans;
  recursive(s, 0, ans);
  return ans;
}

int main() {
  vector<string> p = rec_permutations("ale");
  for(int i=0; i<p.size(); i++){
    cout << p[i] << endl;
  }
}
