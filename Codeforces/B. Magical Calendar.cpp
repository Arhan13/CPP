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
    while(t--){
        ll n,k;cin>>n>>k;
        ll sum=0;
        for(ll i=1;i<=k;i++){
            if(n>=i){
                int sum_added = 1 + (n%i);
                sum += sum_added;
            }
            else{
                sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}