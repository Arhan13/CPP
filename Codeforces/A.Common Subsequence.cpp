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
    int t;
    cin >> t;
    while (t--)
    {   
        int flag=1;
        int len1, len2;
        cin >> len1 >> len2;
        int arr1[len1] = {0}, arr2[len2] = {0};
        for (int i = 0; i < len1; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < len2; i++)
        {
            cin >> arr2[i];
        }
        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; i < len2; j++)
            {
                if (flag == 1)
                {
                    if (arr1[i] == arr2[j])
                    {
                        cout << "YES" << endl;
                        cout << "1"<< " " << arr[i] << endl;
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if(flag==1) {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}