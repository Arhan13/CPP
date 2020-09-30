// B. Binary String Constructing

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
    ll a,b,x;
    cin>>a>>b>>x;
    // a=0, b=1, x =counts
    char c = '1', d = '0';
    if(a>b) {
        swap(c,d);
    }
    ll pairs = x/2;
    // 3 gives 5
    while(pairs--) {
        cout<<c<<d;
        
        a--;
        b--;
    }
    if(a>b && x%2==0) {
        rep(i,1,b+1) {
            cout<<'1';
        }
        rep(i,1,a+1) {
            cout<<'0';
        }
    }
    else if(a>b && x%2) {
        rep(i,1,a+1) {
            cout<<'0';
        }
        rep(i,1,b+1) {
            cout<<'1';
        }
    }
    else if(b>=a && x%2==0) {
        rep(i,1,a+1) {
            cout<<'0';
        }
        rep(i,1,b+1) {
            cout<<'1';
        }
    }
    else if(b>=a && x%2) {
        rep(i,1,b+1) {
            cout<<'1';
        }
        rep(i,1,a+1) {
            cout<<'0';
        }
    }
    cout<<endl;
    return 0;

}