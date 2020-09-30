//Template
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        int k;
        cin >> k;
        char a[8][8];
        int n = 8;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = 'X';
            }
        }
        int counter_limit = k;
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    a[i][j] = 'O';
                    counter++;
                }
                else
                {
                    a[i][j] = '.';
                    counter++;
                }
                if (counter == counter_limit)
                {
                    break;
                }
            }
            if (counter == counter_limit)
            {
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}