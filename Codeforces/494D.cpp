// D. Coins and Queries

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



int minCoinsBU(int N, int coins[], int T)
{
    int dp[100] = {0};
    //Iterate over all states
    for (int n = 1; n <= N; n++)
    {
        dp[n] = INT_MAX;
        for (int i = 0; i < T; i++)
        {
            if (n - coins[i] >= 0)
            {
                int subProb = dp[n - coins[i]];
                dp[n] = min(dp[n], subProb + 1);
            }
        }
    }
    return dp[N];
}


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    ll n,q;
    cin>>n>>q;
    ll arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    // sort(Arr, arr+n);
    while(q--) {
        int counter=0;
        ll target;cin>>target;
        // while(target>0) {
        //     ll low = lower_bound(arr, arr+n, target);
        //     target = target - low;
        //     counter++;
        // }
        // if(target==0) {

        // }
        counter = minCoinsBU(target, arr, n);
        cout<<counter<<endl;
    }
    return 0;

}