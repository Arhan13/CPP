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

char words[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eigth", "nine"};

void printSpellings(int n)
{
    //Base Case
    if (n == 0)
    {
        return;
    }
    printSpellings(n / 10);
    int digit = n % 10;
    cout << words[digit] << " ";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    printSpellings(n);
    cout<<endl;
    return 0;
}