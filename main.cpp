#include<iostream>
#include<vector>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;

vector<vector<int>> subgraphs(vector<vector<int>> adj){
  unordered_set<int> visit;
  vector<vector<int>> ans;
  for(int i=0; i<adj.size(); i++)
    visit.insert(i);
  
  while(!visit.empty()){
    vector<int> subgraph;
    int curr=*visit.begin();
    stack<int> s;
    s.push(curr);
    visit.erase(curr);
    //dfs for undirected graph
    while(!s.empty()){
      int top=s.top();
      subgraph.push_back(top);
      s.pop();
      for(int i=0; i<adj[top].size(); i++){
        int node = adj[top][i];
        if(visit.find(node)!=visit.end()){
          visit.erase(node);
          s.push(node);
        }
      }
    }
    ans.push_back(subgraph);
  }
  return ans;
}

//undirected graph
class Graph{
public:
  vector<vector<int>> adj;
  Graph(int size){
    adj.resize(size);
  }
  void addEdge(int ori, int dest){
    adj[ori-1].push_back(dest-1);
    adj[dest-1].push_back(ori-1);
  }

};


int main(){
  vector<vector<int>> adj;
  // adj.push_back({1});
  // adj.push_back({0,4});
  // adj.push_back({3});
  // adj.push_back({2});
  // adj.push_back({1});

  Graph graph = Graph(5);
  graph.addEdge(1,2);
  graph.addEdge(3,4);
  graph.addEdge(5,2);

  adj = graph.adj;
  vector<vector<int>> sub = subgraphs(adj);

  for(int i=0; i<sub.size(); i++){
    for(int j=0; j<sub[i].size(); j++)
      cout << sub[i][j]+1 << " ";
    cout << endl;
  }
  return 0;
}