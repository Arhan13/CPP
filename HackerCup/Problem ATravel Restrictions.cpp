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
    ll counter = 1;
    while (t--)
    {
        ll n;
        cin >> n;
        char arr[2][n];
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        char arr2[2 * n][2 * n], arr3[2 * n][2 * n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    arr2[i][j] = 'Y';
                }
                else
                {
                    arr2[i][j] = 'N';
                }
            }
        }

        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         if(arr[0][i]=="Y" && arr[1][j]=="Y" && i!=j) {
        //             arr2[i][j] = "Y";
        //         }
        //         else if(arr[0][j]=="Y" && arr[1][i]=="Y" && i!=j) {
        //             arr2[j][i] = "Y";
        //         }
        //     }
        // }

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[0][i + 1] == 'Y' && arr[1][i] == 'Y')
            {
                arr2[i][i + 1] = 'Y';
            }
        }

        for (int i = n - 1; i >= 1; i--)
        {
            if (arr[0][i - 1] == 'Y' && arr[1][i] == 'Y')
            {
                arr2[i][i - 1] = 'Y';
            }
        }

        //Copying arr2 into arr3
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr3[i][j] = arr2[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr2[i][j] == 'Y' && i != j)
                {
                    for (int a = 0; a < n; a++)
                    {
                        if (arr2[j][a] == 'Y' && j != a)
                        {
                            arr3[i][a] = 'Y';
                        }
                    }
                }
            }
        }

        cout << "Case #" << counter++ << ":" << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr3[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}