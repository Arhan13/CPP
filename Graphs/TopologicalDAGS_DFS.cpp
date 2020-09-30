//Template
//BFS go to the source and then the nbrs
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll; 
using namespace std;

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
    //Templated graph
    Graph <string> g;
    g.addEdge("Python", "DataPreprocessing");
    g.addEdge("Python", "PyTorch");
    g.addEdge("Python", "ML");
    g.addEdge("DataPreprocessing", "ML");
    g.addEdge("PyTorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FaceRec");
    g.addEdge("DataSet", "FaceRec");
    g.dfs_DAGS_TOPO();
    return 0;
}