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

    int V;
    list<pair<int, int>> l;
    public:
    Graph(int V){
        this->V = V;
    }
    //Add Edge
    int addEdge(int u, int v){
        l.push_back(make_pair(u, v));
    }
    //Find Set
    int findSet(int i, int parent[]){
        //Base Case
        if(parent[i]==-1){
            return i;
        }
        //Path Compression Optimization
        return parent[i] = findSet(parent[i], parent);
    }
    //Union Set
    void union_set(int x, int y, int parent[]){
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        if(s1!=s2){
            parent[s1] = s2;
        }
    }
    //Contains cycle function
    bool contains_cycle(){
        //DSU logic to check if graph contains cycle or not
        int* parent = new int[V];
        for(int i=0;i<V;i++){
            parent[i] = -1;
        }
        //Iterate over the edge list
        for(auto edge : l){
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if(s1!=s2){
                union_set(s1, s2, parent);
            }
            else{
                cout<<"Same parent "<<s1<<" and "<<s2<<endl;
                return true;
            }
        }
        return false;
    }
};

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    Graph g(4);
    //Zero based indexing;
    //V = V-1;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    cout<<g.contains_cycle()<<endl;
    return 0;

}