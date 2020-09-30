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

int maxSum(int arr[], int n) {
    int dp[100] = {0};
    dp[0] = arr[0]>0 ? arr[0] : 0;
    int max_so_far = dp[0];
    for(int i=1;i<n;i++) {
        dp[i] = dp[i-1] + arr[i];
        if(dp[i]<0) {
            dp[i] = 0;
        }
        max_so_far = max(max_so_far, dp[i]);
    }
    return max_so_far;
}


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    int n = sizeof(arr)/sizeof(int);
    cout<<maxSum(arr, n-1)<<endl;
    return 0;

}