//Template
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll; 
using namespace std;
ll days_counter(ll x, ll value)
{
    ll counter = 0;
    if (x >= value)
    {
        return 0;
    }
    while (x < value)
    {
        x = x * 2;
        counter++;
    }
    // cout<<counter<<endl;
    return counter;
}
int main(){
ios::sync_with_stdio(0);cin.tie(0);
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        ll x;cin>>x;
        vector <ll> pop;
        ll days=0;
        for(int i=0;i<n;i++) {
            ll data;
            cin>>data;
            if(data>=x) {
                pop.push_back(data);
            }
            else {
                days++;
            }
        }
        ll cure_quant=x;
        sort(pop.begin(),pop.end());
        for(int i=0;i<pop.size();i++) {
            ll newdays = days_counter(cure_quant,pop[i]);
            days+=newdays;
            cure_quant = pow(2, newdays) * cure_quant;
            days++;
            cure_quant = pop[i]*2;
        }
        cout<<days<<endl;
    }
    return 0;
}