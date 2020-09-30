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

void permute(char* in, int i){
    //Base Case
    if(in[i]=='\0'){
        cout<<in<<", ";
        return;
    }
    //Recursive Case
    for(int j=1;in[j]!='\0';j++){
        swap(in[i], in[j]);
        permute(in, i+1);
        //Backtracking to restore thr original array
        //as it is passed by refrence
        swap(in[i], in[j]);
    }
}


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    char in[100];
    cin>>in;
    permute(in, 0);
    return 0;

}