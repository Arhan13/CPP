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
        ll n;
        ll piles=0;
        ll arr[n];
        for(int i=0;;i<n;i++) {
            cin>>arr[i];
        }
        if(n%2==0) {
            cout<<"Second"<<endl;
        }
        else {
            cout<<"First"<<endl;
        }
    }
    return 0;

}