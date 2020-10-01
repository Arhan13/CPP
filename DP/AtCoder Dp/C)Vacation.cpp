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

struct activity {
	int A, B, C;
};

int solve(vector<activity> arr, int n){
	int dp[n+1][3];
	dp[1][0] = arr[1].A;
	dp[1][1] = arr[1].B;
	dp[1][2] = arr[1].C;
	for(int i=2;i<=n;i++){
		dp[i][0] = arr[i].A + max(dp[n-1][1], dp[n-1][2]);
		dp[i][1] = arr[i].B + max(dp[n-1][0], dp[n-1][2]);
		dp[i][2] = arr[i].C + max(dp[n-1][0], dp[n-1][1]);
	}
	return max(dp[n][0], max(dp[n][1],dp[n][2]));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	return 0;
	
	int n; cin >> n;
	vector<activity> arr(n + 1);
	for (int i = 1; i<=n; i++) {
		cin >> arr[i].A;
		cin >> arr[i].B;
		cin >> arr[i].C;
	}
	cout<<solve(arr, n);
}
