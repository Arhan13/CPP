//Template
#include <bits/stdc++.h>
#define endl "\n"
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
        int n;
        cin >> n;
        int points_given = 4 * n - 1;
        vector<int> vx = {};
        vector<int> vy = {};
        while (points_given--)
        {
            int x_coordinate, y_coordinate;
            cin >> x_coordinate >> y_coordinate;
            // iterator itx = find(vx.begin(), vx.end(), x_coordinate);
            std::vector<int>::iterator itx = std::find(vx.begin(), vx.end(), x_coordinate);
            std::vector<int>::iterator ity = std::find(vy.begin(), vy.end(), y_coordinate);
            // iterator ity = find(vy.begin(), vy.end(), y_coordinate);
            if (itx != vx.end())
            {
                vx.erase(itx);
            }
            else
            {
                vx.push_back(x_coordinate);
            }
            if (ity != vy.end())
            {
                vy.erase(ity);
            }
            else
            {
                vy.push_back(y_coordinate);
            }
        }
        // for(auto i = vx.begin(); i != vx.end(); i++) {
        //     cout<<*i<<" ";
        // }
        // cout<<endl;
        // for(auto i = vy.begin(); i != vy.end(); i++) {
        //     cout<<*i<<" ";
        // }
        // cout<<endl;
        cout << (*vx.begin()) << " " << (*vy.begin()) << endl;
    }
    return 0;
}