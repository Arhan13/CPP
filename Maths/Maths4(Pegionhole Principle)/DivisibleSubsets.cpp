#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;

void subsetsWithSumDivisibleByN(int arr[], int n){
    int prefixSum[n+1];
    prefixSum[0]=0;
    unordered_map<int,int>mp;
    mp[0]=1;
    int ele=-1,i=1;
    for(i=1;i<=n;i++){
        prefixSum[i]=(prefixSum[i-1]+ (arr[i-1]%n))%n;
        mp[prefixSum[i]]++;
        if(mp[prefixSum[i]]>=2){
            ele=prefixSum[i];
            break;
        }
    }
    if(ele==-1) cout<<ele;
    else{
        int ctr=0,len=0;
        vector<int>v;
        for(i=0;i<=n;i++){
            if(ctr>0){
                v.push_back(i);
                len++;
            }
            if(prefixSum[i]==ele)
                ctr++;
            if(ctr==2)
                break;
        }
        cout<<len<<"\n";
        for(i=0;i<v.size();i++)
            cout<<v[i]<<" ";
    }

}

int main(){
    FAST_IO
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin>>t;
    while(t--){
        int n,i=0;
        cin>>n;
        int arr[n];
        for(;i<n;i++)
            cin>>arr[i];

        subsetsWithSumDivisibleByN(arr,n);
        cout<<"\n";
    }
    return 0;
}
