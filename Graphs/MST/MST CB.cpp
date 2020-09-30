// Given an undirected weighted graph with V nodes and E edges , find the weight of the minimum spanning tree. The IDs of the nodes are between 0 and n-1 inclusive.


// Note : Try using both Kruskal and Prim's Algorithm for this problem

// Input Format
// First line contains two integers V and E.
// Next E lines contain three space separated integers - u ,v and w
// u and v are the nodes , w = weight of edge

// Constraints
// 1 <= V <= 10000
// 1 <= E <= 100000
// 0 <= Weight of each edge <= 10000

// Output Format
// Display a single integer denoting the total weight of the minimum spanning tree.

// Sample Input
// 4 5
// 0 1 10
// 1 2 15
// 0 2 5
// 3 1 2
// 3 2 40
// Sample Output
// 17
// Explanation
// The edge between 2 & 3 with weight=15 and the edge between 3 & 4 with weight = 40 will not be a part of the final MST. The total weight of the remaining edges is 17.
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
        g.addEdge(x, y, w);
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