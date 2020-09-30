//Template
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll; 
using namespace std;

ll days_counter(ll x, ll value) {
    ll counter=0;
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
        // vector<int>::iterator it;
        // it = pop.begin();
        for(ll i=0;i<n;i++) {
            ll data;
            cin>>data;
            pop.push_back(data);
        }
        ll days=0;
        ll cure_quant=x;
        sort(pop.begin(),pop.end());
        ll days_to_be_removed=0;
        while(!(pop.empty())) {
            for(ll j=0;j<n;j++) {
                if(pop[j]==cure_quant) {
                    // pop.erase(it+j);
                    days_to_be_removed++;
                    cure_quant = cure_quant*2;
                    days++;
                }
                else if(pop[j]>cure_quant) {
                    ll new_days = days_counter(cure_quant,pop[j]);
                    days+=new_days;
                    // ll minimum = min( 2*pop[j] , pow(2,new_days)*cure_quant);
                    // if(2*pop[j]<)
                    if( pop[j] <= (pow(2,new_days)*cure_quant) ){
                        cure_quant = 2*pop[j];
                    }
                    else {
                        cure_quant = pow(2,new_days)*cure_quant;
                    }
                    
                    days++;
                    // pop.erase(it+j);
                    days_to_be_removed++;
                }
                else {
                    // pop[j]<x;
                    continue;
                }
            }
            days = days+pop.size()-days_to_be_removed;
            pop.clear();
            // cout<<days<<endl;
        }
        cout<<days<<endl;
    }
    return 0;
}