//Template
#include <bits/stdc++.h>
#define endl "\n"
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
        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        ll first, second, ans = 0;
        first = x;
        if (n == 1 && m == 1)
        {
            ans = x;
            cout << ans << endl;
        }
        else if (y >= 2 * x)
        {
            ans = n * m * x;
            cout << ans << endl;
        }
        else
        {
            if (x < y)
            {
                first = x;
                second = y - x;
                ans = 0;
                ans += (((n * m) + 1) / 2) * first;
                ans += ((n * m) / 2) * second;
                cout << ans << endl;
            }
            else
            {
                ans += (((n * m) + 1) / 2) * y;
                cout << ans << endl;
            }
        }
    }
    return 0;
}