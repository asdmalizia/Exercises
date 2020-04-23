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

// int subgraphs(vector<vector<int>> adj, vector<int> &subgraphs){
//   int ans=0;
//   vector<int> visited(adj.size(),0);
//   while(1){
//     int target=0;
//     while(target<visited.size() && visited[target]){
//       target++;
//     }
//     if(target==visited.size())
//       return ans;
//     ans++;
//     queue<int> q;
//     q.push(target);
//     visited[target]=1;
//     subgraphs[target]=ans;
//     while(!q.empty()){
//       int vert=q.front();
//       q.pop();
//       for(int j=0; j<adj[vert].size(); j++){
//         int viz=adj[vert][j];
//         if(!visited[viz]){
//           visited[viz]=1;
//           subgraphs[viz]=ans;
//           q.push(viz);
//         }
//       }
//     }
//   }
// }

int main(){
  Graph graph = Graph(5);
  graph.addEdge(1,2);
  graph.addEdge(3,4);
  graph.addEdge(5,2);

  vector<vector<int>> sub = subgraphs(graph.adj);
  for(int i=0; i<sub.size(); i++){
    for(int j=0; j<sub[i].size(); j++)
      cout << sub[i][j]+1 << " ";
    cout << endl;
  }

  // vector<int> subgraph(adj.size(),0);
  // cout << subgraphs(adj, subgraph) << endl;

  // for(int i=0; i<subgraph.size(); i++)
  //   cout << subgraph[i] << endl;

  return 0;
}