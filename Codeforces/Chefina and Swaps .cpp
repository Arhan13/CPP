//Template
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll; 
using namespace std;
int main(){
ios::sync_with_stdio(0);cin.tie(0);


    int t;cin>>t;
    while(t--) {
        int master_flag=1;
        int swap_counter=0;
        int n;cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        for(int i=0;i<n;i++) {
            if(a[i]==b[i]) {
                continue;
            }
            else if(a[i]>b[i]) {
                int j=i; int flag=0;
                for(int j=i+1;j<n;j++) {
                    if(a[i]==b[j]) {
                        swap()
                        int temp = a[i];
                        a[i] = b[j];
                        b[j] = temp;
                        flag=1;
                        swap_counter += min(a[i],b[j]);
                        break;
                    }
                }
                if(flag==0) {
                    if(a[i]==a[i+1]) {
                        // b[i] && a[i+1]
                        flag=1;
                        swap(a[0],b[i]);
                        swap_counter += min(a[0],b[i]);
                        swap(b[i],a[i+1]);
                        swap_counter += min(b[i],a[i+1]);
                        
                    }
                }
                
                if(flag==1) {
                    master_flag=1;
                    sort(a,a+n);
                    sort(b,b+n);
                }
                else {
                    master_flag=0;
                    break;
                }
            }

            else if(a[i]<b[i]) {
                int j=i; int flag=0;
                for(int j=i+1;j<n;j++) {
                    if(b[i]==a[j]) {
                        int temp = b[i];
                        b[i] = a[j];
                        a[j] = temp;
                        flag=1;
                        swap_counter += min(b[i],a[j]);
                        break;
                    }
                }
                if(flag==0) {
                    if(b[i]==b[i+1]) {
                        //Swap a[i] && b[i+1]
                        flag=1;
                        swap(b[0],a[i]);
                        swap_counter+=min(b[0],a[i]);
                        swap(a[i],b[i+1]);
                        swap_counter(a[i],b[i+1]);
                        // swap_counter+= min(a[i],b[i+1]);
                        // int temp = a[i];
                        // a[i] = b[i+1];
                        // b[i+1] = temp;
                    }
                }
                if(flag==1) {
                    master_flag=1;
                    sort(a,a+n);
                    sort(b,b+n);
                }
                else {
                    master_flag=0;
                    break;
                }
            }

            if(master_flag==0) {
                break;
            }
        }
        if(master_flag==0) {
            cout<<"-1"<<endl;
        }
        else if(master_flag==1) {
            cout<<swap_counter<<endl;
        }
    }
    return 0;
}