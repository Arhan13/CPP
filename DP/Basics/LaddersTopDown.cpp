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

int laddersTD(int n, int k, int dp[]) {
    //Base Case
    if(n==0) {
        return 1;
    }
    //LookUp
    if(dp[n]!=0) {
        return dp[n];
    }
    //Rec Case
    int ways = 0;
    for(int i=1;i<=k;i++) {
        if(n-i>=0) {
            ways+= laddersTD(n-i, k, dp);
        }
    }
    return dp[n] = ways;
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int n = 4;
    int k = 3;
    int dp[100] = {0};
    cout<<laddersTD(n, k, dp)<<endl;
    return 0;

}