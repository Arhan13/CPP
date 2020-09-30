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

void requiredSubsets(int arr[], int n) {
    int pre[n+1];
    pre[0]=0;
    unordered_map <int,int> mp;
    mp[0]=1;
    int element = -1,i=1;
    for(i=1;i<=n;i++) {
        pre[i] = (pre[i-1] + (arr[i-1]%n))%n;
        mp[pre[i]]++;
        if(mp[pre[i]>=2]) {
            element = pre[i];
            break;
        }
    }
    if(element==-1) {
        cout<<"-1"<<endl;
    }
    else
    {
        int counter=0, len=0;
        vector<int> v;
        for(int i=0;i<n;i++) {
            if(counter>0) {
                v.push_back(i);
                len++;
            }
            if(pre[i]==element) {
                counter++;
            }
            if(counter==2){
                break;
            }
        }
        cout<<len<<endl;

        for(int i=0;i<v.size();i++) {
            cout<<v[i]<<" ";
        }
    }
    
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--) {
        int n;cin>>n;int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        requiredSubsets(arr,n);
        cout<<endl;
    }
    return 0;
}