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
    while(t--){
        int a,b;cin>>a>>b;
        int diff = abs(a-b)/10;
        int ans = ceil(diff);
        cout<<ans<<endl;
    }
    return 0;

}