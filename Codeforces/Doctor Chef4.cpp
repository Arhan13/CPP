//Template
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll; 
using namespace std;

ll days_counter(ll x, ll value) {
    ll counter=0;
    if(x>=value) {
        return 0;
    }
    while(x<value) {
        x = x*2;
        counter++;
    }
    // cout<<counter<<endl;
    return counter;
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--) {
        ll n,x;
        cin>>n>>x;
        vector <ll> pop={};
        vector<ll>::iterator it;
        // it = pop.begin();
        for(ll i=0;i<n;i++) {
            ll data;
            cin>>data;
            pop.push_back(data);
        }
        ll days=0;
        ll infliction_pt; 
        ll cure_quant=x;
        sort(pop.begin(),pop.end());
        ll days_to_be_removed=0;
        if(cure_quant>=pop[n-1]) {
            cout<<n<<endl;
        }
        else {
            for(ll i=0;i<n;i++) {
                if(x<=pop[i]) {
                    infliction_pt = i;
                    break;
                }
            }
            while(2*pop[infliction_pt-1]>=pop[infliction_pt]) {
                infliction_pt--;
            }
            days = 0;
            for(ll i=infliction_pt;i<n;i++) {
                ll newdays = days_counter(cure_quant,pop[i]);
                days+=newdays;
                    if( pop[i] <= (pow(2,new_days)*cure_quant) ){
                        cure_quant = 2*pop[i];
                    }
                    else {
                        cure_quant = 2*pow(2,new_days)*cure_quant;
                    }
                days++;
            }
            for(ll i=infliction_pt-1;i>=0;i--) {
                ll newdays = days_counter(cure_quant,pop[i]);
                days+=newdays;
                if( pop[i] <= (pow(2,new_days)*cure_quant) ){
                    cure_quant = 2*pop[i];
                }
                else {
                    cure_quant = 2*pow(2,new_days)*cure_quant;
                }
                days++;
            }
            cout<<days<<endl;
        }
        // cout<<days<<endl;
    }
    return 0;

}