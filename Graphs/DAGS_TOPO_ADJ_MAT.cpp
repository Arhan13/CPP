//Template
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll; 
using namespace std;

int n;
// /*
// class Graph{
//     //Number of vertex
//     int v;
//     //Number of edged
//     int e;
//     //Adj Matrix;
//     int** adj;

//     public:
//     //Create the graph
//     Graph(int v, int e);
//     //Function to add edge in a graph
//     void addEdge(int start, int e);
//     //Displaying the DFS traversal
//     void DFS(int start, vector<bool>&visited);
// }

// Graph::Graph(int v, int e){
//     this->v = v;
//     this->e = e;
//     //int* arhan = new list<int>[INT_MAX];
//     //Array of arrays
//     //Arrays of pointers
//     adj = new int*[v];
//     for(int row = 0; row< v; row++){
//         adj[row] = new int[v];
//         for(int column=0; column<v; column++){
//             adj[row][column] = 0;
//         }
//     }
// }

// Graph::addEdge(int start, int end){
//     //Considering a bidirectional edge
//     adj[start][end] = 1;
//     adj[end][start] = 1;
// }

// Graph::DFS(int start, vector<bool>& visited){
//     //Printin the start element
//     cout<<start<<endl;
//     //Mark it as visited
//     visited[start] = true;
//     //For every node
//     for(int i=0; i<v; i++){
//         //If the nbr is connected and not visited then perform dfs on it
//         if(adj[start][i]==1 && (!visited[i])){
//             DFS(i, visited);
//         }
//     }
// }
// */

// void DFS(int adjMat[10][10], int start, vector<bool>& visited){
//   map<int, bool> visited;
//   list<int>ordering;
//   for(
//     cout<<start<<endl;
//     visited[start] = true;
//     for(int i=0;i<n;i++){
//         if(adjMat[start][i]==1 && (!visited[i])){
//             DFS(adjMat, i, visited);
//         }
//     }
// }
// int main(){
// ios::sync_with_stdio(0);cin.tie(0);
//     cin>>n;
//     int adjMat[10][10];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>adjMat[i][j];
//           	if(adjMat[i][j]==1){
            	
//             }
//         }
//     }
//     vector<bool> visited(n, false);
//     DFS(adjMat, 0, visited);
//     return 0;

// }

//Template
//BFS go to the source and then the nbrs

template<typename T>

class Graph {
    map<T, list<T>>l;
public:
    void addEdge(T x, T y) {
        l[x].push_back(y);
        // l[y].push_back(x);
    }
    
    void dfs_helper(T src, map<T, bool>&visited, list<T>&ordering) {
        //Recursive function that traverses the graph
        visited[src] = true;
        //Go to all nbrs of that node that is not visited
        for(T nbr : l[src]) { //ADJ list visit
            if(!visited[nbr]) {
                dfs_helper(nbr, visited, ordering);
            }
        }
        ordering.push_front(src);
        return;
    }

    // void dfs(T src) {
    //     map<T, bool> visited;
    //     //Mark all the nodes as visited in the beginning
    //     for(auto p : l) {
    //         T node = p.first;
    //         visited[node] = false;
    //     }
    //     dfs_helper(src, visited);
    // }

    void dfs_DAGS_TOPO() {
        map<T, bool> visited;
        list<T> ordering;
        for(auto p : l) {
            T node = p.first;
            visited[node] = false;
        }
        //Doing dfs on all the nodes in adjlist
        for(auto p : l) {
            T node = p.first;
            if(!visited[node]) {
                dfs_helper(node, visited, ordering);
            }
        }
        
        for(auto node : ordering) {
            cout<<node<<endl;
        }
    }
};

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    Graph <string> g;
    cin>>n;
    int adjMat[10][10];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adjMat[i][j];
          	if(adjMat[i][j]==1){
            	g.addEdge(i, j);
            }
        }
    }
    //Templated graph
    // g.addEdge("Python", "DataPreprocessing");
    // g.addEdge("Python", "PyTorch");
    // g.addEdge("Python", "ML");
    // g.addEdge("DataPreprocessing", "ML");
    // g.addEdge("PyTorch", "DL");
    // g.addEdge("ML", "DL");
    // g.addEdge("DL", "FaceRec");
    // g.addEdge("DataSet", "FaceRec");
    g.dfs_DAGS_TOPO();
    return 0;
}