/*
There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

Input Format
The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.

Constraints
1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

Output Format
An integer that denotes the number of permissible ways to choose a pair of cities.

Sample Input
5 3
0 1
2 3
0 4
Sample Output
6
Explanation
0 1 4 cannot be reached by 2 hence (2,0) (2,1) (2,4) and also 0 1 4 cannot be reached by 3 so (3,0) (3,1) (3,4) hence 6 ways.
*/



//Template
//#include <bits/stdc++.h>
#include <iostream>
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
    void addEdge(int u, int v){
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
    void union_set(int x, int y, int parent[], int rank[]){
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
    //Contains cycle function
    bool contains_cycle(){
        //DSU logic to check if graph contains cycle or not
        int* parent = new int[V];
        int* rank = new int[V];

        for(int i=0;i<V;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
        //Iterate over the edge list
        for(auto edge : l){
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if(s1!=s2){
                union_set(s1, s2, parent, rank);
            }
            else{
                return true;
            }
        }
        delete [] parent;
        delete [] rank;
        return false;
    }

    int pairing(){
        //Init DSU Logic
        int* parent = new int[V];
        int* rank = new int[V];

        for(int i=0;i<V;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
        //Iterate tr=hrough the graph
        for(auto edge : l){
            int i = edge.first;
            int j = edge.second;
            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);
            union_set(s1, s2, parent, rank);
        }
        //Go to all the nodes now
        int ans = 0;
        for(int i=0;i<V;i++){
            ans += (V - rank[findSet(i, parent)]);
        }
        delete [] rank;
        delete [] parent;

        return ans/2;
    }
};

int main(){
ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	Graph g(n);
	while(m--){
		int x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}
	cout<<g.pairing()<<endl;
    return 0;

}