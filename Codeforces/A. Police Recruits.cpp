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
    ll n;
    ll police = 0;
    ll crimes=0;
    while(n--) {
        ll p;cin>>p;
        if(p<0 && police>0) {
            police--;
        }
        else if(p<0 && police==0) {
            crimes++;
        }
        else if(p>0) {
            if(p<=10) {
                police = police+p;
            }
        }
    }
    return 0;

}