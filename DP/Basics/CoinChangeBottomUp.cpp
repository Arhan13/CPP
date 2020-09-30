//Template
#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = int(a); i < int(n); i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll;
using namespace std;

// Time Complexity is O(T*N);
int minCoinsTD(int n, int coins[], int T, int dp[])
{
    //Base Case
    if (n == 0)
    {
        return 0;
    }
    //Look Up
    if (dp[n] != 0)
    {
        return dp[n];
    }
    //Recursive Case
    int ans = INT_MAX;
    for (int i = 0; i < T; i++)
    {
        if (n - coins[i] >= 0)
        {
            int sunProb = minCoinsTD(n - coins[i], coins, T, dp);
            ans = min(ans, sunProb + 1);
        }
    }
    dp[n] = ans;
    return dp[n];
}

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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 15;
    int coins[] = {1, 7, 5};
    int dp[100] = {0};
    int size = sizeof(coins) / sizeof(int);
    cout << minCoinsBU(n, coins, size) << endl;
    return 0;
}