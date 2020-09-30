//Template
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
#define MAX 3000
typedef long long ll; 
using namespace std;

//Dp Array //Space - O(N)
int dp[MAX+1][MAX+1];

string getLCS(string& s, string& t, int len){
    string LCS;
    int i=0,j=0;
    while(len){
        if(s[i]==t[j]){
            LCS.push_back(s[i]);
            i++;j++;
            len--;
        }
        else{
            if(dp[i][j+1] > dp[i+1][j]){
                //This means incrementing j is more benefecial
                j++;
            }
            else{
                i++;
            }
        }
    }
    return LCS;
}

int lenLCS(string& s, string& t, int i, int j){
    //Top Down DP
    //1) BASE CASE
    if( i>=(s.length()) || j>=(t.length()) ){
        //Length has been exceeded and cannot do anything
        return 0;
    }
    //2) DP LOOK UP
    if(dp[i][j]!= -1){
        return dp[i][j];
    }
    //3) RECURRENCE RELATION
    //TWO CASES
    if(s[i]==t[j]){
        return dp[i][j] = 1 + lenLCS(s, t, i+1, j+1);
    }
    else{
        return dp[i][j] = max(lenLCS(s, t, i, j+1), lenLCS(s, t, i+1, j));
    }
}

string solve(string &s, string &t){
    memset(dp, -1, sizeof(dp));
    int len = lenLCS(s,t,0,0);
    return getLCS(s,t,len);
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    string s, t;
    cin>>s>>t;
    cout<<solve(s, t)<<endl;
    return 0;

}