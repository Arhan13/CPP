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
    public:
    list<int> *l;//List of list of node connected to vertics
    int V;//Number of vertices
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x, int y){
        //Directed Graph
        l[x].push_back(y);
    }
    void topological_sort_bfs(){
        //indegree
        int *indegree = new int[V];
        //0 indegree for all
        for(int i=0;i<V;i++){
            indegree[i] = 0;
        }
        //Updating indegree
        for(int i=0;i<V;i++){
            for(auto y : l[i]){
                indegree[y]++;
            }
        }
        queue<int> q;
        //1) Find nodes with 0 indegree
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //Start removing elements from the queue
        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto nbr : l[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }
};


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(2,5);
    g.topological_sort_bfs();
    return 0;

}