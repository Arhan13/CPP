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

int ladder_bottom_up(int n, int k) {
    int dp[100] = {0};
    dp[0] = 1; //Start Case
    for(int i=1;i<=n;i++) {
        dp[i] = 0;
        for(int j=1;j<=k;j++) {
            if(i-j>=0) {
                dp[i] += dp[i-j];
            }
        }
    }
    for(int i=0;i<=n;i++) {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return dp[n];
}


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int n = 6;
    int k = 3;
    cout<<"Ways are: "<<ladder_bottom_up(n,k)<<endl;
    return 0;

}