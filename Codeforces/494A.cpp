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

        ll n;cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        ll longest_counter=0;
        ll counter=0;
        for(int i=0;i<n-1;i++) {
            ll data = arr[i];
            if(arr[i+1]==arr[i]) {
                counter++;
            }
            else if(arr[i+1]!=arr[i]) {
                if(counter>=longest_counter) {
                    longest_counter = counter;
                }
            }
        }
        if(n==1) {
            longest_counter=1;
        }
        cout<<longest_counter<<endl;
    return 0;

}