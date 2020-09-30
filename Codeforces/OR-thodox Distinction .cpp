//Template
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// Driver program
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        bool flag = 0;
        vector<ll> sets;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (ll i = 0; i < n; i++)
        {
            ll m = 0;
            ll n = arr[i];
            ll j = i - 1;
            sets.push_back(n);
            while (m != n && j >= 0)
            {
                m = m | arr[j];
                n = n | arr[j];
                sets.push_back(n);
                j--;
            }
        }
        sort(sets.begin(), sets.end());
        for (int i = 0; i < sets.size() - 1; i++)
        {
            if (sets[i] == sets[i + 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}
