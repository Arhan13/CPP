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

int rod_cutting_bu(int arr[], int totalLen) {
    int dp[100] = {0};
    for(int len=1; len<=totalLen; len++) {
        int best =0;
        for(int cut = 1; cut<=len ;cut++) {
            best = max(best, arr[cut] + arr[len-cut]);
        }
        dp[len] = best;
    }
    return dp[totalLen];
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int prices_of_lengths[100];
    int totalLen;
    cin>>totalLen;
    for(int i=0;i<totalLen;i++) {
        cin>>prices_of_lengths[i];
    }
    int ans = rod_cutting_bu(prices_of_lengths, totalLen);
    cout<<ans<<endl;
    return 0;
}

/*
    io - 2 3 2 5
    op - 8

*/