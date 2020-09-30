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
    int people = 0;
    float x = 1.0; //denotes the prob of same birthday
    float num = 365, denom = 365;
    float p;
    cin >> p;
    if (p == 1.0)
    {
        cout << "366" << endl;
        return 0;
    }
    while (x > (1 - p))
    {
        x = x * (num / denom);
        num--;
        people++;
        // cout<<"People "<<people<<" and x "<<x<<endl;
    }
    cout << "Required People are : " << people << endl;
    return 0;
}