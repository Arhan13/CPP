//Template
#include <bits/stdc++.h>
#include<cstring>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll; 
using namespace std;

ll a[100005], pre[100005];

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        memset(pre, 0, sizeof(pre));
        pre[0]=1;//Frequency array
        ll sum=0;
        for(ll i=0;i<n;i++) {
            cin>>a[i];
            sum += a[i];
            sum %= n;
            sum = (sum+n)%n;
            pre[sum]++;
        }
        ll ans=0;
        for(ll i=0;i<n;i++) {
            ll m = pre[i];
            ans += m*(m-1)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}