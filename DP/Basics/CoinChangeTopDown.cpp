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

int minCoins(int n, int coins[], int T, int dp[]) {
    //Base Case
    if(n==0) {
        return 0;
    }
    //Look Up
    if(dp[n]!=0) {
        return dp[n];
    }
    //Recursive Case
    int ans = INT_MAX;
    for(int i=0;i<T;i++) {
        if(n-coins[i]>=0) {
            int sunProb = minCoins(n-coins[i], coins, T, dp);
            ans = min(ans, sunProb+1);
        }
    }
    dp[n] = ans;
    return dp[n];
}
int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int n = 15;
    int coins[] = {1,7,5};
    int dp[100] = {0};
    int size = sizeof(coins)/sizeof(int);
    cout<<minCoins(n, coins, size, dp)<<endl;
    return 0;

}