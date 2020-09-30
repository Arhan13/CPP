//Template
//Minimum element in a range
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll; 
using namespace std;

void buildTree(int *a, int s, int e, int *tree, int index) {
    if(s==e) {
        tree[index] = a[s];
        return;
    }
    //Recursive Case
    int mid = (s+e)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int arr[] = {1,3,2,-5,6,4};
    int n = sizeof(arr)/sizeof(int);
    int * tree = new int[4*n+1];
    buildTree(arr,0,n-1,tree,1);//1 is the index
    for(int i=1;i<=13;i++) {
        cout<<tree[i]<<" ";
    }
    return 0;

}