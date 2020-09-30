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

int x,y,GCD;

int gcd(int a, int b) {
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
}

void extendedEuclidMethod(int a, int b) {
    //Base Case
    if(b==0) {
        x = 1;
        y = 0;
        GCD = a;
        return;
    }
    //Recursive Case
    extendedEuclidMethod(b,a%b);
    int cx = y; //Current x
    int cy = x-(a/b)*y; //Current y
    // cout<<cx<<","<<cy<<endl;
    x = cx;
    y = cy;
}

//Assuming the mmi exists ie gcd(a,m)==1;
int inverseMultiplcativeModulo(int a, int m) {
    extendedEuclidMethod(a,m);
    //Here x will basically be the required b(mmi)
    return (x+m)%m; //For negative values
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    //  18X+30Y = 6
    // extendedEuclidMethod(18,30);
    // cout<<x<<","<<y<<endl;
    cout<<inverseMultiplcativeModulo(6,7)<<endl;
    //Expected output is 6
    return 0;
}