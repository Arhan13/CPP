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

struct item {
    ll value;
    ll weight;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    // int n,w;cin>>n>>w;
    // vector<pair<int, int>> v;
    // for(int i=1;i<=n;i++){
    //     cin>>v[i].first;
    //     cin>>v[i].second;
    // }
    // int dp[n+1][n+1];
    // for(int i=1;i<=n;i++){
    //     dp[0][i] = 0;
    // }
    // for(int i=1;i<=n;i++){
    //     if(w<0){
    //         break;
    //     }
    //     if((w-v[i].first)>=0){
    //         if()
    //         dp[i][w] = max(dp[i-1][w], v[i].second + dp[i-1][w-v[i].first]);
    //     }
    //     else{
    //         dp[i][w] = dp[i-1][w];
    //     }
    // }
    // cout<<dp[n][w]<<endl;
    ll n, W; cin >> n >> W;
    vector<item> arr(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i].weight;
        cin >> arr[i].value;
    }
    //Dp Array
    ll dp[n + 1][W+1];
    //Base Case
    //We will pick the fist item in a very specific case if the value is exactly equal to the target
    for (ll w = 0; w<=W; w++) {
        dp[1][w] = 0;
    }
    //We can only pick the first item
    dp[1][arr[1].weight] = arr[1].value;
    for (ll i = 2; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            //Not taking the ith item
            dp[i][w] = dp[i - 1][w];
            //Checking and taking the ith element
            if (arr[i].weight > w) {
                continue;
            }
            dp[i][w] = max(dp[i][w], arr[i].value + dp[i - 1][w - arr[i].weight]);
        }
    }
    cout<<*max_element(dp[n], dp[n]+W+1);
    return 0;
}