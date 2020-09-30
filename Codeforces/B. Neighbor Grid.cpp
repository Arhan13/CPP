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
    while(t--) {
        int row,column;
        cin>>row>>column;
        int arr[row][column];
        for(int i=0;i<row;i++) {
            for(int j=0;j<column;j++) {
                cin>>arr[i][j];
            }
        }
        int flag=1;
        for(int i=0;i<row;i++) {
            for(int j=0;i<column;j++) {
                if(arr[i][j]==0) {
                    continue;
                }
                else if(arr[i][j]==1) {
                    if(j-1>=0) {
                        arr[i][j-1]++;
                    }
                    else if(j+1<column) {
                        arr[i][j+1]++;
                    }
                    else if(i+1<row) {
                        arr[i+1][j]++;
                    }
                    else if(i-1>=0) {
                        arr[i-1][j]++;
                    }
                    else {
                        cout<<"NO"<<endl;
                        flag=0;
                        break;
                    }
                }
                else if(arr[i][j]==2) {
                    if(j-1>=0 && i+1<row) {
                        arr[i][j-1]++;
                        arr[i+1][j]++;
                    }
                    else if(j+1<column && i+1<row) {
                        arr[i][j+1]++;
                        arr[i+1][j]++;
                    }
                    else if(i-1>=0 && j-1>=0) {
                        arr[i-1][j]++;
                        arr[i][j-1]++;
                    }
                    else if(i-1>=0 && j+1<column) {
                        arr[i-1][j]++;
                        arr[i][j+1]++;
                    }
                    else {
                        cout<<"NO"<<endl;
                        flag=0;
                        break;
                    }
                }
                else if(arr[i][j]==3) {
                    if(j-1>=0 && i+1<row && j+1<column) {
                        arr[i][j-1]++;
                        arr[i+1][j]++;
                        arr[i][j+1]++;
                    }
                    else if(i+1<row && j+1<column && i-1>=0) {
                        arr[i+1][j]++;
                        arr[i][j+1]++;
                        arr[i-1][j]++;
                    }
                    else if(j+1<column && i-1>=0 && j-1>=0) {
                        arr[i][j+1]++;
                        arr[i-1][j]++;
                        arr[i][j-1]++;
                    }
                    else if(i-1>=0 && j-1>=0 && i+1<row) {
                        arr[i-1][j]++;
                        arr[i][j-1]++;
                        arr[i+1][j]++;
                    }
                    else {
                        cout<<"NO"<<endl;
                        flag=0;
                        break;
                    }
                }
                else if(arr[i][j]==4) {
                    if(i+1<row && j+1<column && i-1>=0 && j-1>=0) {
                        arr[i+1][j]++;
                        arr[i][j+1]++;
                        arr[i-1][j]++;
                        arr[i][j-1]++;
                    }
                    else {
                        cout<<"NO"<<endl;
                        flag=0;
                        break;
                    }
                }
            }
        }
        if(flag==1) {
            cout<<"YES"<<endl;
            for(int i=0;i<row;i++) {
                for(int j=0;i<column;j++) {
                    cout<<arr[i][j]<<" ";
                }
                 cout<<endl;
            }
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;

}