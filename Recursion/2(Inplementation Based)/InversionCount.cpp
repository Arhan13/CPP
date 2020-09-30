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

int merge(int *a, int s, int e) {
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;

    int temp[100000];

    int counter=0;

    while(i<=mid and j<=e) {
        if(a[i]<=a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
            counter += mid-(i-1);
        }
    }
    //Filling the remaining part of the array
    while(i<=mid) {
        temp[k++] = a[i++];
    }
    while(j<=e) {
        temp[k++] = a[j++];
    }
    //Copying temp into the arr
    for(int i=s;i<=e;i++) {
        a[i] = temp[i];
    }

    return counter;
}

int inversion_count(int *a, int s, int e) {
    //Base Case
    if(s>=e) {
        return 0;
    }
    //Merge
    int mid = (s+e)/2;
    int x = inversion_count(a,s,mid);
    int y = inversion_count(a,mid+1,e);
    int z = merge(a,s,e);//Cross inversions
    return x+y+z;
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int arr[] = {1,5,2,6,3,0};
    int n = sizeof(arr)/sizeof(int);
    cout<<inversion_count(arr,0,n-1)<<endl;
    return 0;
}