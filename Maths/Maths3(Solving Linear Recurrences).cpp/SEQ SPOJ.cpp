//Template
#include <bits/stdc++.h>
#include<vector>
#define ll long long
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
using namespace std;
#define MOD 1000000000

ll k;
vector<ll> a,b,c;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B) {
    vector<vector<ll>> C(k+1, vector<ll>(k+1));
    //Logic to multiply the matrix
    for(int i=1;i<=k;i++) {
        for(int j=1;j<=k;j++) {
            for(int x=1;x<=k;x++) {
                C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
            }
        }
    }
    return C;
}


vector<vector<ll>> power(vector<vector<ll>> A, ll p) {
    //Base Case
    if(p==1) {
        return A;
    }
    //If pow is odd
    if(p&1) {
        return multiply(A, power(A, p-1));
    }
    //If pow is even 
    vector<vector<ll>> X = power(A, p/2);
    return multiply(X,X);
}


ll compute(ll n) {
    //Base Case
    if(n==0) {
        return 0;
    }
    if(n<=k) {
        return b[n-1];
    }
    //Otherwise we need to use matrix exponentiation
    vector <ll> F1(k+1);
    //Creatin the F1 vector
    //Indexed from 1
    for(int i=1;i<=k;i++) {
        F1[i] = b[i-1];
    }
    //Formation of the transformation matrix
    vector<vector<ll>> T(k+1, vector<ll> (k+1));

    for(int i=1;i<=k;i++) {
        for(int j=1;j<=k;j++) {
            if(i<k) {
                //Fill with 1s and 0s
                if(j==i+1) {
                    T[i][j] = 1;
                }
                else {
                    T[i][j] = 0;
                }
            }
            //For the last row ie i==k
            else {
                T[i][j] = c[k-j];//COefficients in reverse order
            }
        }
    }
    //We need to some power of vector
    T = power(T, n-1);
    //Matrix with the vector to get nth element
    ll res=0;
    for(int i=1;i<=k;i++) {
        res = (res + (T[1][i]*F1[i])%MOD)%MOD;
    }
    return res;
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    ll t,n,num;
    cin>>t;
    while(t--) {
        cin>>k;
        //Input for F1 vector
        for(int i=0;i<k;i++) {
            cin>>num;
            b.push_back(num);
        }
        //Coefficients
        for(int i=0;i<k;i++) {
            cin>>num;
            c.push_back(num);
        }
        //Value of n - nth term is required
        cin>>n;
        cout<<compute(n)<<endl;
        b.clear(); c.clear();
    }
    return 0;
}