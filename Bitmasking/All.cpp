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

//Is number odd
bool is_Odd(int n) {
    return (n&1);
}

//Find ith bit
int get_ith_bit(int n,int i) {
    int mask = (1<<i); // creating a mask
    int bit = (n&mask)>0 : 1 ? 0;
    return bit;
}

//Set ith bit to 1
int set_ith_bit(int n, int i) {
    int mask = 1<<i; //creating a mask
    int ans = n|mask;
    return ans;
}


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    
}
