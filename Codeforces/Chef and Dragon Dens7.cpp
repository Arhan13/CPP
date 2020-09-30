//Template
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    ll heights[n];
    ll tastes[n];
    for (ll i = 1; i <= n; i++)
    {
        cin >> heights[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> tastes[i];
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll index;
            cin >> index;
            ll new_taste;
            cin >> new_taste;
            tastes[index] = new_taste;
        }
        else if (type == 2)
        {
            ll start;
            cin >> start;
            ll end;
            cin >> end;
            ll max_peak = INT_MIN;
            ll current_peack = 0;
            int flag = 0;
            ll taste_sum = 0;
            taste_sum = tastes[end];
            if (heights[start] > heights[end])
            {
                if (start > end && abs(start - end) > 1)
                {
                    for (ll i = end + 1; i < start; i++)
                    {
                        if (heights[i] > heights[end] && heights[i] < heights[start] && heights[i] > max_peak)
                        {
                            max_peak = heights[i];
                            taste_sum += tastes[i];
                        }
                        else if (heights[i] >= heights[start])
                        {
                            flag = 1;
                        }
                    }
                    if (flag == 0)
                    {
                        taste_sum += tastes[start];
                    }
                    if (flag == 1)
                    {
                        cout << "-1" << endl;
                    }
                    else if (flag == 0)
                    {
                        cout << taste_sum << endl;
                    }
                }
                else if (start < end && abs(start - end) > 1)
                {
                    for (ll i = end - 1; i > start; i--)
                    {
                        if (heights[i] > heights[end] && heights[i] < heights[start] && heights[i] > max_peak)
                        {
                            max_peak = heights[i];
                            taste_sum += tastes[i];
                        }
                        else if (heights[i] >= heights[start])
                        {
                            flag = 1;
                        }
                    }
                    if (flag == 0)
                    {
                        taste_sum += tastes[start];
                    }
                    if (flag == 1)
                    {
                        cout << "-1" << endl;
                    }
                    if (flag == 0)
                    {
                        cout << taste_sum << endl;
                    }
                }
                else if (abs(start - end) == 1)
                {
                    taste_sum = tastes[start] + tastes[end];
                    cout << taste_sum << endl;
                }
                else if (abs(start - end) == 0)
                {
                    taste_sum = tastes[start];
                    cout << taste_sum << endl;
                }
            }
            else if (heights[start] == heights[end] && start == end)
            {
                taste_sum = tastes[start];
                cout << taste_sum << endl;
            }
            else
            {
                flag = 1;
                if (flag == 1)
                {
                    cout << "-1" << endl;
                }
            }
        }
    }
    return 0;
}