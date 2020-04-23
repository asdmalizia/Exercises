#include<iostream>
#include<vector>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;

//undirected graph
class Graph{
public:
  vector<vector<int>> adj;
  Graph(int size){
    adj.resize(size);
  }
  void addEdge(int ori, int dest){
    adj[ori].push_back(dest);
    adj[dest].push_back(ori);
  }

  void DFS(int curr, vector<int> &visited, vector<int> &path){
    visited[curr]=1;
    for(auto it=adj[curr].begin(); it!=adj[curr].end(); it++){
      if(!visited[*it])
        DFS(*it, visited, path);
    }
    path.push_back(curr);
  }

  vector<vector<int>> subgraphs(){
    vector<int> visited(adj.size(),0);
    vector<vector<int>> ans;
    for(int i=0; i<adj.size(); i++){
      if(!visited[i]){
        vector<int> path;
        DFS(i, visited, path);
        ans.push_back(path);
      }
    }
    return ans;
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
  graph.addEdge(2,1);
  graph.addEdge(1,0);
  graph.addEdge(0,2);
  graph.addEdge(0,3);
  graph.addEdge(3,4);

  vector<vector<int>> sub = graph.subgraphs();
  for(int i=0; i<sub.size(); i++){
    for(int j=0; j<sub[i].size(); j++)
      cout << sub[i][j] << " ";
    cout << endl;
  }

  // vector<int> subgraph(adj.size(),0);
  // cout << subgraphs(adj, subgraph) << endl;

  // for(int i=0; i<subgraph.size(); i++)
  //   cout << subgraph[i] << endl;

  return 0;
}