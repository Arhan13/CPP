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

int profit(int wines[], int i, int j, int y, int dp[][100]) {
    //Base Case
    if(i>j) {
        return 0;
    }
    //LookUp
    if(dp[i][j]!=0) {
        return dp[i][j];
    }
    //Recursive Case
    int op1 = wines[i]*y + profit(wines, i+1, j, y+1, dp);
    int op2 = wines[j]*y + profit(wines, i, j-1, y+1, dp);

    return max(op1, op2);
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int wines[] = {2,3,5,1,4};
    int n = sizeof(wines)/sizeof(int);
    int y =1;
    int dp[100][100] = {0};
    cout<<profit(wines, 0, n-1, y, dp)<<endl;
    return 0;

}