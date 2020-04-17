#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void print(int i){
  cout << i << endl;
}

void BFS(int start, vector<vector<int>> adj, void (*func)(int)){
  if(start >= adj.size())
    return;
  queue<int> q;
  vector<int> visited(adj.size(),0);
  q.push(start);
  visited[start]=1;
  while(!q.empty()){
    int vert = q.front();
    q.pop();
    func(vert);
    for(int i=0; i< adj[vert].size(); i++)
      if(!visited[adj[vert][i]]){
        q.push(adj[vert][i]);
        visited[adj[vert][i]]=1;
      }
  }
}

int main(){
  vector<vector<int>> adj;
  adj.push_back({1,2,3});
  adj.push_back({0,2});
  adj.push_back({0,1,4});
  adj.push_back({0});
  adj.push_back({2});

  BFS(5, adj, print);
  return 0;
}