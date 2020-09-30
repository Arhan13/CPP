//Template
#include <bits/stdc++.h>
#include<cstring>
#include<list>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll; 
using namespace std;

class Graph {
    //Adj List
    unordered_map<string, list<pair<string, int>>>l;
public:
    void addEdge(string x, string y, bool bidir, int wt) { // x is initial // bidir is bidirectional
        l[x].push_back(make_pair(y, wt));
        if(bidir) {
            l[y].push_back(make_pair(x, wt));
        }
    }
    void printAdjList() {
        //Iterate over all the keys
        for(auto p: l) { //All pair
            string city = p.first;
            list<pair<string, int>> nbrs = p.second;
            cout<<city<<" -> ";
            for(auto nbr: nbrs) {
                string destination = nbr.first;
                int distance = nbr.second;
                cout<<destination<<" "<<distance<<", ";
            }
            cout<<endl;
        }
    }
};


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("A", "C", true, 10);
    g.addEdge("B", "D", true, 30);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);
    g.printAdjList();
    return 0;

}