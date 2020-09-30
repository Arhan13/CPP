// //Template
// #include <bits/stdc++.h>
// #define rep(i,a,n) for(int i=int (a);i<int (n);i++)
// #define endl "\n"
// #define vi vector<int>
// #define se set<char>
// #define pb push_back
// #define um unordered_map
// typedef long long ll; 
// using namespace std;


// string removeDuplicate(string s){
//     set<char> set_kk(s.begin(), s.end());
//     int i=0;
//     for(auto x : set_kk){
//         s[i++] = x;
//     }
//     s[i]='\0';
//     return s;
// }

// int main(){
// ios::sync_with_stdio(0);cin.tie(0);
//     int t;cin>>t;
//     while(t--){
//         string s1,s2;
//         cin>>s1>>s2;
//         sort(s1.begin(), s1.end());
//         sort(s2.begin(), s2.end());
//         s1 = removeDuplicate(s1);
//         s2 = removeDuplicate(s1);
//         if(strcmp(s1,s2)==0){
//             cout<<"YES"<<endl;
//         }
//         else{
//             cout<"NO"<<endl;
//         }
//     }
//     return 0;

// }

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

bool contains(string s1, string s2){
    map<char, int> mp;
    for(int i=0;i<s1.size();i++){
        mp[s1[i]]++;
    }
    for(int i=0;i<s2.size();i++){
        if(mp[s2[i]>0]){
            return true;
        }
    }
    return false;
}


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    int flag=0;
    while (t--)
    {
        string s1,s2;
        map<char, int> mp;
        cin>>s1>>s2;
        if(contains(s1,s2)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;

}