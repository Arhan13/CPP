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
        ll Rcounter=0;
        ll Ucounter=0;
        ll Dcounter=0;
        ll Lcounter=0;
        string s1;
        cin>>s1;
        cout<<s1<<endl;
        cout<<s1.length()<<endl;
        for(int i=0;i<s1.length();i++) {
            if(s1[i]=='R') {
                Rcounter++;
            }
            else if(s1[i]=='L') {
                Lcounter++;
            }
            else if(s1[i]=='U') {
                Ucounter++;
            }
            else if(s1[i]=='D') {
                Dcounter++;
            }
        }
        ll x1,y1;
        cin>>x1>>y1;
        ll q;cin>>q;
        while(q--) {
            ll x2,y2;
            cin>>x2>>y2;
            ll diffx = x2-x1;
            ll diffy = y2-y1;
            int flag=0;
            int counter=0;
            if(diffx>0) {
                if(diffx<=Rcounter) {
                    counter+=diffx;
                    flag=0;
                }
                else{
                    flag=1;
                }
            }
            if(diffy>0) {
                if(diffy<=Ucounter) {
                    counter+=diffy;
                    flag=0;
                }
                else{
                    flag=1;
                }
            }
            if(diffx<0) {
                if(diffx<=Lcounter) {
                    counter = counter + (diffx*-1);
                    flag=0;
                }
                else{
                    flag=1;
                }
            }
            if(diffy>0) {
                if(diffy<=Dcounter) {
                    counter = counter + (diffy*-1);
                    flag=0;
                }
                else{
                    flag=1;
                }
            }
            if(flag==1){
                cout<<"NO"<<endl;
            }
            else {
                cout<<"YES "<<counter<<endl;
            }
        }
    }
    return 0;

}