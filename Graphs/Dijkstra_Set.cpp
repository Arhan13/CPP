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
template <typename T>

class Graph{
    unordered_map<T, list<T, list<pair<T, int>>> m;
public:
    void addEdge(T u, T v, int dist, bool bidir = true){
        m[u].push_back(make_pair(v , dist));
        if(bidir){
            m[v].push_back(make_pair(u, dist));
        }
    }
    void printAdj(){
        //Lets try to print the adj list
        //Iterate over all the key value pair in the map
        for(auto j : m){
            cout<<j.first<<"->";
            //Iterate over the list of cities
            for(auto l : j.second){
                cout<<"("<<l.first<<", "<<l.second<<")";
            }
            cout<<endl;
        }
    }
    void dijsktraSSSP(T src){
        unordered_map<T, int> dist;
        //Set all distance to infinity
        for(auto j : m){
            dist[j.first] = INT_MAX;
        }
        //Make a set to find all nodes with minimum distance
        set<pair<int , T>>s;
        //Insert the source node init
        dist[src] = 0;
        s.insert(make_pair(0, src));
        while(!s.empty()){
            //Find the first pair
            auto p = *(s.begin());
            T node = p.second;
            T nodeDist = p.first;
            s.erase(s.begin());
            //Iterate over nbr of current node
            for(auto childPair : m[node]){
                //Update the distance
                if(nodeDist+childPair.second < dist[childPair.first]){
                    //We need to update the set
                    //We will do this by removing the old pair and inserting the new pair


                    //Finding the required node inside the set
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f!=s.end()){
                        s.erse(f);
                    }

                    //Insert the new pair inside the set
                    dist[dest] = nodeDist+childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
    }
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);

    return 0;

}