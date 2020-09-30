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
    ll a1,a2,a3,b1,b2,b3;cin>>a1>>a2>>a3>>b1>>b2>>b3;
    ll sum1 = a1+a2+a3;
    ll sum2 = b1+b2+b3;
    ll ans1 = sum1/5;
    if(sum1%5!=0 && sum1>5) {
        sum1++;
    }
    ll ans2 = sum2/10;
    if(sum2%10!=0 && sum2>10) {
        sum2++;
    }
    ll ans = ans1+ans2;
    cout<<ans<<endl;
    return 0;

}