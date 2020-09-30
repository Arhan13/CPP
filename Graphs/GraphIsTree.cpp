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

class Graph{

    int V;//Number of vertices
    list<int> *adj;//Pointer to the array for adjacent list;
    public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];//Array of type list of size V;
    }
    void addEdge(int x, int y){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool isCyclicUntil(int v, bool visited[], int parent){
        visited[v] = true;
        //Recur through all the vertices adj to the given node vertex
        for(auto i = adj[v].begin(); i!=adj[v].end(); i++){
            //If not visited check if cycle exists
            if(!visited[*i]){
                if(isCyclicUntil(*i, visited, v)){
                    //If cycle exists in the adj list(childs) we will have to return true
                    return true;
                }
            }
            //If visited and not equal to parent
            //Its visited twice
            else if(*i!=parent){
                return true;
            }
        }
        // for(auto i = adj[v].begin(); i!=adj[v].end(); i++){
        //     if(!visited[*i]){
        //         if(isCyclicUntil(*i, visited, v)){
        //             return true;
        //         }
        //     }
        //     else if(*i!=parent){
        //         return true;
        //     }
        // }
        return false;
    }

    bool isTree(){
        bool *visited = new bool[V];
        //Marking every node as not visited
        for(int i=0;i<V;i++){
            visited[i] = false;
        }
        //Vertex vistedArray parent
        if(isCyclicUntil(0, visited, -1)){
            return false;
        }
        //Now check if we left any node as not visited
        //After starting bfs or dfs from 0 vertex
        for(int i=0;i<V;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    Graph g(5);
    //g.addEdge(1,2);
    g.addEdge(1,0);
    g.addEdge(2,0);
    g.addEdge(0,3);
    g.addEdge(3,4);
    if(g.isTree()){
        cout<<"Tree"<<endl;
    }
    else{
        cout<<"Graph"<<endl;
    }
    return 0;

}