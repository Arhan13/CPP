//Template

//Time Complexity is O(n*k);
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
    
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    
    int n k; cin>>n>>k;
    vi arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vi dp(n+1);
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        dp[i] = INT_MAX;
        for(int j = i-1; j>=1 && (i-j)<=k; j--){
            dp[i] = min(dp[i], abs(arr[i]-arr[j])+dp[j]);
        }
    }
    cout<<dp[n]<<endl;
    
    return 0;
}
