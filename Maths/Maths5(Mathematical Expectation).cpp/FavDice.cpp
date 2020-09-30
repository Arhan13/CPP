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
int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--) {
        int n;cin>>n;
        int copy_of_n = n;
        float ans=0,sum=0;
        for(int i=1;i<=n;i++) {
            sum += ((float)1/i);
        }
        ans = (float)sum*copy_of_n;
        printf("%.2f\n", ans);
    }
    return 0;
}