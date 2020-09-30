//Template
#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = int(a); i < int(n); i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll;
using namespace std;

class Graph
{
    int V;
    //List of arrays
    list<int> *l;

public:
    Graph(int V)
    {
        //V vertices in the graph
        this->V = V;
        //List of arrays
        l = new list<int>[V];
    }
    //Undirected edge addition
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            for (auto nbr : l[i])
            {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }

    //Cycle logic
    bool cycle_helper_ud_dfs(int node, bool *visited, int parent)
    {
        visited[node] = true;
        for (auto nbr : l[node])
        {
            if (!visited[nbr])
            {
                //go recursively and call the cycle detect function on that node
                bool cycle_mila = cycle_helper_ud_dfs(nbr, visited, node);
                if (cycle_mila == true)
                {
                    return true;
                }
            }
            else if(nbr!=parent){
                return true;
            }
        }
        return false;
    }

    bool contains_cycle_ud_dfs()
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        return cycle_helper_ud_dfs(0, visited, -1);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(3,2);
   // g.addEdge(2,1);
    if(g.contains_cycle_ud_dfs()){
        cout<<"Contains cycle"<<endl;
    }
    else{
        cout<<"No cycle baby"<<endl;
    }
    
    return 0;
}