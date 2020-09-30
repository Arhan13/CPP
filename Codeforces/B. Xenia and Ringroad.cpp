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
    ll n,m;cin>>n>>m;
    ll arr[m];
    ll ans=0;
    ll location = 1;
    for(int i=0;i<n;i++) {
        ll new_location;
        cin>>new_location;
        if(new_location<location) {
            ans+= n - (location-new_location);
        }
        else {
            ans += 
        }
    }
    cout<<distance<<endl;
    return 0;

}