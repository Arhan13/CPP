//Template
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;

string removeZero(string str) 
{ 
    // Count trailing zeros 
    int i = 0; 
    while (str[i] == '0') 
       i++; 
  
    // The erase function removes i characters 
    // from given index (0 here) 
    str.erase(0, i); 
  
    return str; 
} 

string DecimalToBinaryString(int a)
{
    uint b = (uint)a;
    string binary = "";
    uint mask = 0x80000000u;
    while (mask > 0)
    {
        binary += ((b & mask) == 0) ? '0' : '1';
        mask >>= 1;
    }
    cout << binary << endl;
    return binary;
}

int stringtoint(string k)
{
    int value = 0;
    for (int i = k.length() - 1; i >= 0; i--)
        if (k[i] == 0)
        {
            continue;
        }
        else
        {
            ans += pow(2, k.length() - i - 1);
        }

    return value;
}

int binaryConcatination(int x, int y)
{
    string sx = DecimalToBinaryString(x);
    string sy = DecimalToBinaryString(y);
    removeZero(sx);
    removeZero(sy);
    string binXplusY = sx + sy;
    string binYplusX = sy + sx;
    

    int xplusy = stringtoint(binXplusY);
    int yplusx = stringtoint(binYplusX);

    return xplusy-yplusx;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans_max=INT_MIN;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                ans_max = max(ans_max, binaryConcatination(arr[i], arr[j]));
            }
        }
        cout<<ans_max<<endl;
    }
    return 0;
}