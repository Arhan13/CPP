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
    //List of Arrays
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V]L;
    } //We have v vertices in the graph
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printAdjList()
    {
        //Iterate over all vertices
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << " -> ";
            for (int nbr : l[i])
            {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.printAdjList();
    return 0;
}