//Template
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
#define inf 10e9+1;
typedef long long ll; 
using namespace std;


struct item{
    int value;
    int weight;
};

long long solve(vector<item> arr, int n, int W){
    ll maxValue = 1000*n;
    ll dp[n+1][maxValue+1];
    for(int val=0; val<=maxValue; val++){
        dp[1][val] = inf;
    }
    dp[1][0] = 0;//Not picking the fist element;
    dp[1][arr[1].value] = arr[1].weight;//Picking the first object
    //Bottom up on the first i items
    for(ll i=2; i<=n;i++){
        for(ll v=0; v<=maxValue; v++){
            //Not including the new item
            dp[i][v] = dp[i-1][v];
            //Selecting the ith element
            if(arr[i].value > v){
                continue;
            }
            dp[i][v] = min( dp[i][v], arr[i].weight + dp[i-1][v - arr[i].value] );
        }
    }
    ll ans;
    for(ll val=0;val<=maxValue;val++){
        if(dp[n][val]<=W){
            ans = val;
        }
    }
    return ans;
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int n;cin>>n;
    int W;cin>>W;
    vector<item> arr(n+1);
    for(int i=1; i<=n; i++){
        cin>>arr[i].weight;
        cin>>arr[i].value;
    }
    cout<<solve(arr, n, W);
    return 0;

}