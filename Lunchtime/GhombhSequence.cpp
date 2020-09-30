#include <bits/stdc++.h> 
typedef long long ll; 
using namespace std; 

vector <ll> dp2;
ll mod = 1000000007;


void compute() {
    dp2[1] = 1;
    for(ll i=0;i<e10;i++) {
        dp2[i] = (1 + dp2[i - dp2[dp2[i - 1]]])%mod; 
    }
}

ll Golomb(ll r, ll l) 
{ 
    
    // ll sum=0;
	// ll dp[r + 1]; 

	// // base cases 

	// dp[1] = 1; 
	// for (ll i = 2; i <= r; i++) 
	// { 
	// 	dp[i] = 1 + dp[i - dp[dp[i - 1]]]; 
	// } 
    for(ll i=l;i<=r;i++) {
        sum += (dp2[i]*dp2[i])%mod;
    }
    return sum;
}
int main() 
{ 
	int n = 9; 
    ll t;cin>>t;
    compute();
    while(t--) {
        ll l,r;
        cin>>l>>r;
        ll ans = Golomb(r,l); 
        cout<<ans<<endl;
    }
	
	return 0; 
} 
