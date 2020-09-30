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

int maxSumSapceOpt(int arr[], int n) {
    int current_sum = 0;
    int max_so_far = 0;
    for(int i=0;i<n;i++) {
         current_sum += arr[i];
         if(current_sum<0) {
             current_sum  =0;
         }
         max_so_far = max(max_so_far, current_sum);
    }
    return max_so_far;
}


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    int n = sizeof(arr)/sizeof(int);
    cout<<maxSumSapceOpt(arr, n-1)<<endl;
    return 0;

}