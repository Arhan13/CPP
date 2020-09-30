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
        ll n;cin>>n;
        l counter_2=0;counter_3=0;
        while(n%2==0) {
            n /=2;
            counter_2++;
        }
        while(n%3==0) {
            n /= 3;
            counter_3++;
        }
        if(n==1 && counter_2<=counter_3) {
            cout<< 2*counter_3-counter_2<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}