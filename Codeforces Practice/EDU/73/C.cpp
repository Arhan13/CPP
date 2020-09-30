// 6
// 1 1 1
// 3 6 0
// 0 0 0
// 0 1 1
// 10 1 10
// 4 4 1

// 1
// 3
// 0
// 0
// 1
// 3

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
int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int ans = 0;
        int c,m,x;cin>>c>>m>>x;
        int d = max(c,m) - min(c,m);
        x+=d;
        if(c>m){
            c-=d;
        }
        else{
            m-=d;
        }
        int mm = min(c, min(m,x));
        ans+=mm;
        c-=mm;
        m-=mm;
        x-=mm;
        ans+=floor((c+m)/3);
        cout<<ans<<endl;
    }
    return 0;
}


