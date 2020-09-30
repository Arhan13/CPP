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
        ll n,x;
        cin>>n>>x;
        vector <ll> pop={};
        vector<ll>::iterator it;
        int giveup_flag=0;
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
            ll pointer1=n-1;
            ll pointer2=0;
            while(pointer2<=n-2) {
                if(cure_quant>=pop[pointer2]) {
                    days++;
                    cure_quant = 2*pop[pointer2];
                    pointer2++;
                }
                else if(cure_quant<pop[pointer2]){
                    if(2*cure_quant<pop[pointer1]) {
                        days++;
                        cure_quant = 2*cure_quant;
                    }
                   else if(2*cure_quant>=pop[pointer1]) {
                        cout<<"Im here"<<endl;
                        days++;
                        days+= pointer1-pointer2+1;
                        giveup_flag=1;
                        break;
                    }
                }
            }
            if(giveup_flag==0) {
                while(cure_quant<pop[pointer1]) {
                    cure_quant *=2;
                    days++;
                }
                if(cure_quant>=pop[pointer1]) {
                    days++;
                }
            }
            cout<<days<<endl;
            

        }
    }
    return 0;

}