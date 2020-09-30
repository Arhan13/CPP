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
        bool yes = false;
        string s,s1;
        s1 = " not ";
        getline(cin,s);
        ll n = s.size();
        if(n==3) {
            if(s=="not") {
                yes = true;
            }
            if(n>3) {
                if(s.substr(0,4) =="not " || s.substr(n-4, 4)=="not ") {
                    yes = true;
                }
            }

                size_t found  = s.find(s1);
                if(found != string:: npos || yes) {
                    cout<<"Real Fancy"<<endl;
                }
                else {
                    cout<<"regularly fancy"<<endl;
                }
            }
        }
    }
    return 0;

}