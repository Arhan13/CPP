//Template
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll; 
using namespace std;

int fact(int n); 
  
int nCr(int n, int r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 

int fact(int n) 
{ 
    int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

void Catlan_Number(int n) {
    int num = nCr(2*n, n);
    int denom = n+1;
    int ans = num/denom;
    cout<<ans;
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    cout<<Catlan_Number(n)<<endl;
}