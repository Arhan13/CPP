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

void replacePi(char a[], int i) {
    //Base case 
    if(a[i]=='\0' || a[i+1]=='\0') {
        return;
    }
    if(a[i]=='p' and a[i+1]=='i') {
        //Shifting and replacement with 3.14
        int j=i+2;
        //Taking j to the end of the array
        while(a[j]!='\0') {
            j++;
        }
        while(j>=i+2) {
            a[j+2] = a[j];
            j--;
        }
        //Replacing the remainig part
        a[i]='3';
        a[i+1]='.';
        a[i+2]='1';
        a[i+3]='4';
        replacePi(a,i+4);
    }
    else {
        replacePi(a,i+1);
    }
    return;
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    char a[100];
    cin>>a;
    // int size = sizeof(a)/sizeof(char);
    int start=0;
    replacePi(a, start);
    cout<<a<<endl;
    return 0;
}