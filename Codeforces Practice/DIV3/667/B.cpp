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
    int t;cin>>t;
    ll a,b,x,y,n;
    while(t--){
        cin>>a>>b>>x>>y>>n;
        // while(n--){
        //     if(a>b && (a-1)>=x){
        //         a--;n--;
        //     }
        //     else if(b>a && (b-1)>=y){
        //         b--;n--;
        //     }
        //     else if(a==b){
        //         if(x>y && (a-1)>=x){
        //             a--;n--;
        //         }
        //         else if(y>x && (b-1)>=y){
        //             b--;n--;
        //         }
        //         else{
        //             if((a-1)>=x){
        //                 a--,n--;
        //             }
        //             else if((b-1)>=y){
        //                 b--,n--;
        //             }
        //         }
        //     }
        // }
        // cout<<a*b<<endl;
        ll ans = 1e18;
        for(int i=0;i<2;i++){
            int da = min(n. a-x);
            int db = min(n-da, b-y);
            int ans = min(ans, 1ll*(a-da)*(y-db));
            swap(x,y);
            swap(a,b);
        }
        cout<<ans<<endl;
    }
    return 0;

}