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
        ll n;cin>>n;
        ll a[n],b[n];
        unordered_map<ll,ll> mp,mp1,mp2;
   
        for(int i=0;i<n;i++) {
            cin>>a[i];
            mp[a[i]]++;
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
            mp[b[i]]++;
        }
        sort(a,a+n);
        sort(b,b+n);
        int flag=0;
        ll minimum_element = min(a[0],b[0]);
        for(auto u:mp) {
            if(u.second%2==1) {
                flag=1;
                break;
            }
            else {
                mp1[u.first] = u.second/2;

            }
        }
        if(flag) {
            cout<<"-1\n";
            continue;
        }
        else {
            mp2 = mp1;
            vector<ll> v1,v2;
            for(int i=0;i<n;i++) {
                if(mp1[a[i]]) {
                    mp1[a[i]]--;
                }
                else {
                    v1.push_back(a[i]);
                }
            }
            for(int i=0;i<n;i++) {
                if(mp2[b[i]]) {
                    mp2[b[i]]--;
                }
                else {
                    v2.push_back(b[i]);
                }
            }
            sort(v1.begin(),v1.end());
            sort(v2.begin(), v2.end(), greater<ll>());
            ll y = v1.size();
            if(y==0) {
                cout<<"0\n";
            }
            else {
                ll ans=0;
                for(int i=0;i<y;i++) {
                    ans+= min(2*minimum_element, min(v1[i],v2[i]) );
                }
                cout<<ans<<endl;
            }
        }
    }
    return 0;

}