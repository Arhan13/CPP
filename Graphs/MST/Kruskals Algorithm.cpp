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

class DSU{

    int* parent;
    int* rank;
public:
    DSU(int n){
        parent = new int[n];
        rank = new int[n];
        //Init the parent and rank
        //parent = -1 && rank = 1
        for(int i=0;i<n;i++){
            rank[i] = 1;
            parent[i] = -1;
        }
    }
    //Find Function
    int find(int i){
        //Base case
        if(parent[i]==-1){
            return i;
        }
        //Path Compression
        return parent[i] = find(parent[i]);
    }
    //unite(union)
    void unite(int x, int y){
        int s1 = find(x);
        int s2 = find(y);
        if(s1!=s2){
            //Union by rank
            if(rank[s1]<rank[s2]){
                parent[s1] = s2;
                //Because S1 got attanched to S2
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                //Because S2 got attanched to S1
                rank[s1] += rank[s2];
            }
        }
    }

};

class Graph{
    // w x y
    // w - weight
    vector<vector<int>>edgeList;
    int V;
public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int x, int y, int w){
        edgeList.push_back({w, x, y});
    }
    int kruskal_mst(){
        //Main Code
        //1) Sort all the edges based upon weight
        sort(edgeList.begin(), edgeList.end());

        //Init a DSU
        DSU s(V);
        
        int ans = 0;
        for(auto edge : edgeList){
            //edge is a vector
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            //take that edge in mst if it dosen't form cycle
            if(s.find(x)!=s.find(y)){
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    // Graph g(4);
    // g.addEdge(0,1,1);
    // g.addEdge(1,3,3);
    // g.addEdge(3,2,4);
    // g.addEdge(2,0,2);
    // g.addEdge(0,3,2);
    // g.addEdge(1,2,2);
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        g.addEdge(x-1,y-1,w);
    }
    cout<<g.kruskal_mst()<<endl;
    return 0;

}