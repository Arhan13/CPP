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
int stringToInt(char* a, int n) {
    if(n==0) {
        return 0;//Null string
    }
    int digit = a[n-1]-'0';//Last digit
    int small_ans = stringToInt(a,n-1);
    return small_ans*10 + digit;
}
int main(){
ios::sync_with_stdio(0);cin.tie(0);
    char a[] = "1234";
    int len = strlen(a);
    int x = stringToInt(a,len);
    cout<<x<<endl;
    cout<<x+1<<endl;
    return 0;
}