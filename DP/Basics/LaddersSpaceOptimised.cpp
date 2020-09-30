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

int ladder_optimised(int n, int k) {
    int dp[100] = {0};
    dp[0] = dp[1] = 1;
    for(int i=2;i<=k;i++) {
        dp[i] = 2*dp[i-1];
    }
    for(int i=k+1;i<=n;i++) {
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }
    return dp[n];
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int n = 6;
    int k = 3;
    cout<<"Ways are: "<<ladder_optimised(n,k)<<endl;
    return 0;

}