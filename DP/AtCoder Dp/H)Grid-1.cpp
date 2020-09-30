//Template
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
#define MOD 1000000007
typedef long long ll;
using namespace std;

char grid[1002][1002];

ll solve(int n, int m){
    ll dp[n+1][m+1];
    dp[n][m] = 1;//Empty path from n,m to n,m
    for(ll i=n;i>=1;i--){
        for(ll j=m;j>=1;j--){
            if(i==n && j==m){
                continue;
            }
            //Hits a block
            if(grid[i][j]=='#'){
                dp[i][j] = 0;
            }
            //Go up then down and check
            else{
               dp[i][j] = (((i==n) ? 0 : dp[i+1][j])%MOD + ((j==m) ? 0 : dp[i][j+1])%MOD)%MOD; 
            }
            
        }
    }
    dp[1][1] = dp[1][1]%MOD;
    return dp[1][1];
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);

    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<solve(n, m)<<endl;
    return 0;

}