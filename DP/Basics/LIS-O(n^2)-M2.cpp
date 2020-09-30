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
    ll n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int dp[n+1];
    dp[0] = INT_MIN;
    for(int i=1; i<=n; i++) {
        dp[i] = INT_MAX;
    }
    for(int i=0;i<n;i++) {
        for(int length = 0; length < n; length++) {
            if(dp[length] < a[i] && a[i] < dp[length+1]) {
                dp[length + 1] = a[i];
            }
        }
    }
    int LIS = 0;
    for(int i=1;i<=n;i++) {
        if(dp[i]!=INT_MAX) {
            LIS++;
        }
    }
    cout<<LIS<<endl;
    return 0;

}