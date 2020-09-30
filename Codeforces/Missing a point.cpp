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
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        int number_of_points = 4*n-1;
        unordered_set<ll> give_xs, given_ys;
        for(int i=0;i<number_of_points;i++) {
            ll x,y;
            cin>>x>>y;
            if(given_xs.count(x)) {
                given_xs.erase(x)
            }
            else{
                given_xs.insert(x);
            }
            if(given_ys.count(y)) {
                given_ys.erase(y)
            }
            else{
                given_ys.insert(y);
            }
        }
        cout<<(*given_xs.begin()) <<" "<< (*given_ys.begin()) <<endl;
    }
    return 0;
}