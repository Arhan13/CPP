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

vector<int> graph[100001];
int dp[100001];

int solve(int src){
    if(dp[src]!=-1){
        return dp[src];
    }
    int maxChild = 0;//Stores the maximum path from each child if its not itself leaf
    bool leaf = 1;
    for(auto child : graph[src]){
        leaf = 0;
        maxChild = max(maxChild, solve(child));
    }
    return dp[src] = leaf ? 0 : 1 + maxChild;
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int n,m;cin>>n>>m;
    //n = number of nodes
    //m = number of edges
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, solve(i));
    }
    cout<<ans<<endl;
    return 0;

}