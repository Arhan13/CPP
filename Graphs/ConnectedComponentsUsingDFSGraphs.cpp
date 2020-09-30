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
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T source) {
        map <T, int> visited;
        queue<T> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()) {
            T node = q.front();
            q.pop(); cout<<node<<" ";
            for(int nbr : l[node]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    //Mark the neighbour as visited
                    visited[nbr] = true;
                }
            }
        }
    }

    void dfs_helper(T src, map<T, bool> &visited) {
        //Recursive function that traverses the graph
        cout<<src<<" ";
        visited[src] = true;
        //Go to all nbrs of that node that is not visited
        for(T nbr : l[src]) { //ADJ list visit
            if(!visited[nbr]) {
                dfs_helper(nbr, visited);
            }
        }

    }

    void dfs(T src) {
        map<T, bool> visited;
        //Mark all the nodes as visited in the beginning
        for(auto p : l) {
            T node = p.first;
            visited[node] = false;
        }
        dfs_helper(src, visited);
    }

    void dfs_connectedGraphs() {
        map<T, bool> visited;
        for(auto p : l) {
            T node = p.first;
            visited[node] = false;
        }
        //Doing dfs on all the nodes in adjlist
        int counter=1;
        for(auto p : l) {
            T node = p.first;
            if(!visited[node]) {
                cout<<"Component "<<counter<<"-->";
                dfs_helper(node, visited);
                cout<<endl;
                counter++;
            }
        }
    }
};

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    //Templated graph
    Graph <int> g;
    //Connected Component One
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    //Connected Component Two
    g.addEdge(8, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 9);

    g.dfs_connectedGraphs();
    return 0;
}