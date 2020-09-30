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
    //1 -> ((a,w1), (b,w2), (c,w3));
    //Adjacency List
    //Array of vectors
    vector<pair<int, int>> *l;
    int V;
public:
    Graph(int n){
        this->V = n;
        l = new vector<pair<int, int>>[n];
    }

    void addEdge(int x, int y, int w){
        //Node and Weight
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim_mst(){
        //Most Important
        //Min Heap - priority_queue <int, vector<int>, greater<int>> gquiz; 
        // priority_queue <int> g = gq; 
        //Init a Min Heap
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater< pair<int, int>> > Q;

        //Another Array - Visited Array
        //Visited array that denotes whether a node has been incli=uded in MST or not
        bool* visited = new bool[V]{0};
        int ans = 0;

        //begin from the source node
        Q.push({0,0}); // weight, node
        // Q is in the form of weight and node
        while(!Q.empty()){
            //pick out the edge with minimum weight
            //Top of the min heap
            auto best = Q.top();
            Q.pop();
            int to = best.second; //
            int weight = best.first;

            //If visited then continue
            if(visited[to]){
                continue;
            }
            
            //otherwise pick this current edge
            ans += weight;
            visited[to] = 1;

            //add he new edges in the Q
            for(auto x : l[to]){
                //If not visited
                if(visited[x.first]==0){
                    Q.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
};


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        g.addEdge(x-1, y-1,w);
    }
    //x y w
    // g.addEdge(0,1,1);
    // g.addEdge(0,2,2);
    // g.addEdge(0,3,2);
    // g.addEdge(1,2,2);
    // g.addEdge(1,3,2);
    // g.addEdge(3,3,2);
    cout<<g.prim_mst()<<endl;
    return 0;

}