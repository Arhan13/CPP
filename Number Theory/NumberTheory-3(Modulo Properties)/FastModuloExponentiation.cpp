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

ll fastModExp(ll a, ll b, ll m) {
    ll res = 1;
    while(b>0) {
        if(b&1) {
            res = (res*a)%m;
        }
        a = (a*a)%m;
        b = b>>1; //Right shift
    }
    return res;
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    ll a,b;
    cin>>a>>b;
    ll ans = fastModExp(a,b,100000);
    cout<<ans<<endl;
    return 0;
}