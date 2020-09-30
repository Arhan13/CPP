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
        int n;cin>>n;
        int counter=0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int temp = arr[i]&arr[j];
                for(int i=0;i<n;i++) {
                    if(arr[i]==temp) {
                        counter++;
                    }
                }
            }
        }
    }
    return 0;

}