//Template
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll; 
using namespace std;
int main(){
ios::sync_with_stdio(0);cin.tie(0);
    ll t;cin>>t;
    while(t--) {
        ll rectangles;cin>>rectangles;
        ll points = 4*n-1;
        map<ll,ll> x_coordinates, y_coordinates;
        ll xs, ys;
        for(int i=0;i<points;i++) {
            cin>>xs>>ys;
            x_coordinates[xs]++;
            y_coordinates[ys]++;

        }
        for( auto it: x_coordinates) {
            if(it.second % 2 == 1) {
                cout<<it.first<<" ";
                break;
            }
        }
        for( auto it: y_coordinates) {
            if( it.second %2==1) {
                cout<<it.first<<" ";
                break;
            }
        }
        cout<<endl;
    }
    return 0;

}