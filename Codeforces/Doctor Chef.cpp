//Template
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll; 
using namespace std;

ll days_counter(ll x, ll value) {
    ll counter=1;
    while(x<value) {
        x = x*2;
        counter++;
    }
    return counter;
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--) {
        ll n,x;
        cin>>n>>x;
        int populations[n];
        for(int i=0;i<n;i++) {
            cin>>populations[i];
        }
        int population_value = populations[0];
        int same_population_counter=0;
        int days=0;
        for(int i=0;i<n;i++) {
            if(populations[i]==population_value) {
                same_population_counter++;
            }
        }
        if(same_population_counter==n) {
            if(x>=population_value) {
                days = n;
            }
            else if(x>=((population_value+1)/2)) {
                days = n+1;
            }
            else {
                days = days_counter(x, (population_value+1)/2) +n;
            }
        }
        else {
            sort(populations, populations+n, greater<int>());
            if(x>=population_value) {
                days = n;
            }
            else if(x>=((population_value+1)/2)) {
                days = n+1;
            }
            else {
                days = days_counter(x, (population_value+1)/2) +n;
            }
        }
        cout<<days<<endl;
    }
    return 0;

}