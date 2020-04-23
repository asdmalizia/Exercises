#include<iostream>
#include<vector>

using namespace std;

class Graph{
public:
  int** adj;
  int size;
  Graph(int size): size(size){
    adj = new int*[size];
    for(int i=0; i<size; i++){
      adj[i] = new int[size];
      adj[i][i]=1;
    }
  }

  void addEdge(int ori, int des){
    adj[ori][des]=1;
  }

  void DFS(int curr, vector<int> &visited, vector<int> &path){
    visited[curr]=1;
    for(int i=0; i<size; i++){
      if(adj[curr][i] && !visited[i])
        DFS(i, visited, path);
    }
    path.push_back(curr);
  }

  vector<int> fillPath(){
    vector<int> visited(size,0);
    vector<int> path;
    for(int i=0; i<size; i++){
      if(!visited[i])
        DFS(i, visited, path);
    }
    return path;
  }

  void reverse(){
    for(int i=0; i<size; i++){
      for(int j=i; j<size; j++)
        if((adj[i][j]==1 && adj[j][i]==0) 
        || (adj[i][j]==0 && adj[j][i]==1)){
          adj[i][j]=1-adj[i][j];
          adj[j][i]=1-adj[j][i];
        }
    }
  }

  bool hasRingRoad(){
    vector<int> path = fillPath();
    reverse();
    vector<int> visited(size, 0);
    for(int i=path.size()-1; i>=0; i--){
      vector<int> road;
      //if we wanted to keep track of all srtongly connected components
      //we should only call DFS for not visited vertexes
      DFS(path[i], visited, road);
      if(road.size()>1)
        return true;
    }
    return false;
  }

  void print(){
    for(int i=0; i<size; i++){
      for(int j=0;j<size; j++)
        cout << adj[i][j] << " ";
      cout << endl;
    }
  }

};

int main(){
  Graph graph = Graph(3);
  graph.addEdge(0,2);
  // graph.addEdge(1,0);
  // graph.addEdge(2,1);

  graph.print();
  cout << graph.hasRingRoad() << endl;
  graph.print();

  return 0;
}