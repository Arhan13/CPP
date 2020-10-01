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

void multiply(int *a, int &n, int no)
{ //No is basically the number we need to multiply
    int carry = 0;
    for (int i = 0; i < n; i++)
    {
        int product = a[i] * no + carry;
        a[i] = product % 10;
        carry = product / 10;
    }
    while (carry)
    {
        a[n] = carry % 10;
        carry = carry / 10;
        n++;
    }
}

void big_factorial(int number)
{
    int *a = new int[1000];
    for (int i = 0; i < 1000; i++)
    {
        a[i] = 0;
    }
    a[0] = 1;
    int n = 1; //Size of the number;
    for (int i = 2; i <= number; i++)
    {
        multiply(a, n, i);
    }
    //Print the result
    for (int i = n - 1; i >= 0; i--)
    {
        cout << a[i] << " ";
    }
    delete[] a; //deleting the array to free its memory
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    big_factorial(n); // calling the function
    return 0;
}
