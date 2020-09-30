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
int main(){
ios::sync_with_stdio(0);cin.tie(0);
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    int dp[n+1];
    fill(dp,dp+n+1, -1e10); 
    //Base Case 
    dp[0] = 0;
    //Removing and checking
    for(int i=a;i<=n;i++) {
        dp[i] = max(dp[i], dp[i-a]+1);
    }
    for(int i=b;i<=n;i++) {
        dp[i] = max(dp[i], dp[i-b]+1);
    }
    for(int i=c;i<=n;i++) {
        dp[i] = max(dp[i], dp[i-c]+1);
    }
    cout<<dp[n]<<endl;
    return 0;

}