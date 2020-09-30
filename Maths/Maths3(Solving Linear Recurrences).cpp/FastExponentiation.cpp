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
int pow(int a, int n) {
    if(n==0) {
        return 1;
    }
    int subproblem = pow(a,n/2);
    //If n is odd
    if(n&1){
        return a*subproblem*subproblem;
    }
    //If n is even
    return subproblem*subproblem;
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int base,power;
    cin>>base>>power;
    int ans = pow(base, power);
    cout<<ans<<endl;
    return 0;
}