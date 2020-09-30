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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, n, m;
        // cin >> a >> b >> n >> m;
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&n);
        scanf("%lld",&m);
        int flag = 1;
        if (a + b == 0)
        {
            flag = 0;
        }
        while (m--)
        {
            if (a > b)
            {
                b--;
            }
            else
            {
                a--;
            }
        }
        if (b < 0)
        {
            flag = 0;
        }
        if (a < 0)
        {
            flag = 0;
        }

        while (n--)
        {
            if (a > b)
            {
                a--;
            }
            else
            {
                b--;
            }
        }
        if (a < 0)
        {
            flag = 0;
        }
        if (b < 0)
        {
            flag = 0;
        }
        if (flag == 0)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }
    return 0;
}