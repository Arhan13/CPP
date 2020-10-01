//Template
//Frog 1 Dp series AtCoder

#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll; 

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    
    int n;cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vi dp(n+1);
    dp[1] = 0;
    for(int i=2;i<n+1;i++){
        int option1 = abs(arr[i]-arr[i-1]) + dp[i-1];
        int option2 = (i==2) ? INT_MAX : abs(arr[i]-arr[i-2]) + dp[i-2];
        dp[i] = min(option2, option1);
    }
    cout<<dp[n];
    
    return 0;
}
