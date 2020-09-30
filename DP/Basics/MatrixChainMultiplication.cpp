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

int Solution ::solve(vector<int> &A)
{
    int dp[200][200];
    memset(dp, 0, sizeof dp);
    int n = A.size() - 1;
    for (int i = 1; i < n; i++)
    {
        int r = 0, c = i;
        while (c < n)
        {
            int val = INT_MAX;
            for (int pivot = r; pivot < c; pivot++)
            {
                val = min(val, dp[r][pivot] + dp[pivot + 1][c] + A[r] * A[pivot + 1] * A[c + 1]);
            }
            dp[r][c] = val;
            r++;
            c++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
