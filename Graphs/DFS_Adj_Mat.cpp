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
class Graph{

    //Number of vertex
    int v;
    //Number of edged
    int e;
    //Adj Matrix;
    int** adj;

    public:
    //Create the graph
    Graph(int v, int e);
    //Function to add edge in a graph
    void addEdge(int start, int e);
    //Displaying the DFS traversal
    void DFS(int start, vector<bool>&visited);
}

Graph::Graph(int v, int e){
    this->v = v;
    this->e = e;
    //int* arhan = new list<int>[INT_MAX];
    //Array of arrays
    //Arrays of pointers
    adj = new int*[v];
    for(int row = 0; row< v; row++){
        adj[row] = new int[v];
        for(int column=0; column<v; column++){
            adj[row][column] = 0;
        }
    }
}

Graph::addEdge(int start, int end){
    //Considering a bidirectional edge
    adj[start][end] = 1;
    adj[end][start] = 1;
}

Graph::DFS(int start, vector<bool>& visited){
    //Printin the start element
    cout<<start<<endl;
    //Mark it as visited
    visited[start] = true;
    //For every node
    for(int i=0; i<v; i++){
        //If the nbr is connected and not visited then perform dfs on it
        if(adj[start][i]==1 && (!visited[i])){
            DFS(i, visited);
        }
    }
}

void DFS_MAIN(int adjMat[][n], int strat, vector<bool>& visited){
    cout<<start<<endl;
    visited[start] = true;
    for(int i=0;i<n;i++){
        if(adjMat[start][i]==1 && (!visited[i])){
            DFS_MAIN(i, visited);
        }
    }
}
int main(){
ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    int adjMat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adjMat[i][j];
        }
    }
    vector<bool> visited(n, false);
    void DFS_MAIN(int adjMat[][n], 0, visited);
    return 0;

}