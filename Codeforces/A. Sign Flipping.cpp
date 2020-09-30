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
    while(t--) {
        ll n;cin>>n;
        int arr[n];
        for(int i=1;i<=n;i++) {
            cin>>arr[i];
        }
        for(int i=1;i<=n;i++) {
            if(i%2==0) {
                if(arr[i]>0) {
                    arr[i]*=-1;
                }
            }
            else if(i%2!=0){
                if(arr[i]<0) {
                    arr[i]*=-1;
                }
            }
        }
        for(int i=1;i<=n;i++) {
            cout<<arr[i]<<" "; 
        }
        cout<<endl;
    }
    return 0;

}