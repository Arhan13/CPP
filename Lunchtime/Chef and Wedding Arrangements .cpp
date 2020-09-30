//Template
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll; 
using namespace std;
int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--) {
        ll n,k;cin>>n>>k;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        ll ppl_on_table=0;
        ll negated_ppl=0;
        ll cost=0;
        for(int i=1;i<n;i++) {
            if(arr[i]!=arr[i-1]) {
                if(ppl_on_table==0) {
                    cost += k;
                }
                ppl_on_table++;
            }
            else {
                if(k>negated_ppl){
                    negated_ppl++;
                }
                else {
                    negated_ppl=0;
                    ppl_on_table=0;
                    ppl_on_table++;
                }
            }
        }
    }
    return 0;

}