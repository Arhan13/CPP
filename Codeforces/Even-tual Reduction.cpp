//Template
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll; 
using namespace std;
int main(){
ios::sync_with_stdio(0);cin.tie(0);
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        string s;cin>>s;
        // cout<<s.size()<<endl;
        if(s.length()%2!=0) {
            cout<<"NO"<<endl;
        }
        else {
            map<char, int>m;
            for(int i=0;i<s.size();i++) {
                m[s[i]]++;
            }
            int flag=0;
            for(auto c: m) {
                if(c.second%2!=0) {
                    cout<<"NO"<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==0) {
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;

}