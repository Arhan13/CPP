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
        int minimum = min(a[0],b[0]);
        cout<<minimum<<endl;
        for(int i=0;i<n;i++) {
            if(a[i]==b[i]) {
                continue;
            }
            else if(a[i]>b[i]) {
                    int j=i; int flag=0;

                    if(b[i]==b[j+1]) {
                        //Swap a[i] and b[j+1]
                        // using b[0]
                        flag=1;
                        if(b[0]==minimum){
                            if(min(a[i],b[j+1])>b[0]*2){
                                swap(a[i],b[0]);
                                swap_counter+= min(a[i],b[0]);
                                swap(a[i],b[j+1]);
                                swap_counter+=min(a[i],b[j+1]);
                            }
                            else {
                                swap(a[i],b[j+1]);
                                swap_counter+=min(a[i],b[j+1]);
                            }
                        }
                        else {
                            //Swap a[i] and b[j+1]
                            //Using a[0];
                            if(min(a[i],b[j+1])>a[0]*2){ //b[0]=a[0]
                                swap(a[0],b[j+1]);
                                swap_counter+= min(a[0],b[j+1]);
                                swap(b[j+1],a[i]);
                                swap_counter+= min(b[j+1],a[i]);

                                // swap(a[i],b[0]);
                                // swap_counter+= min(a[i],b[0]);
                                // swap(a[i],b[j+1]);
                                // swap_counter+=min(a[i],b[j+1]);
                            }
                            else {
                                swap(a[i],b[j+1]);
                                swap_counter+=min(a[i],b[j+1]);
                            }
                        }

                        
                    }
                
                    if(flag==0) {
                        if(a[i]==a[i+1]) {
                            // b[i] && a[i+1]
                            //Uisng a[0]
                            flag=1;
                            if(a[0]==minimum) {

                                if(min(b[i],a[i+1])>a[0]*2){

                                swap(a[0],b[i]);
                                swap_counter += min(a[0],b[i]);
                                swap(b[i],a[i+1]);
                                swap_counter += min(b[i],a[i+1]);
                            }

                            else{
                                swap(b[i],a[i+1]);
                                swap_counter+= min(b[i],a[i+1]);
                            }
                        }
                            else {
                                //Swap b[i] && a[i+1]
                                //Using b[0]
                                if(min(b[i],a[i+1])>b[0]*2){
                                    swap(b[0],a[i+1]);
                                    swap_counter+= min(b[0],a[i+1]);
                                    swap(b[i],a[i+1]);
                                    swap_counter+= min(b[i],a[i+1]);
                                    // swap(a[0],b[i]);
                                    // swap_counter += min(a[0],b[i]);
                                    // swap(b[i],a[i+1]);
                                    // swap_counter += min(b[i],a[i+1]);
                                }
                                else{
                                    swap(b[i],a[i+1]);
                                    swap_counter+= min(b[i],a[i+1]);
                                }
                            }  
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

                    if(a[i]==a[j+1]) {
                        flag=1;
                        //Swap b[i],a[j+1]
                        //Using a[0]
                        if(a[0]==minimum) {
                            if(min(b[i],a[j+1])>a[0]*2) {
                                swap(b[i],a[0]);
                                swap_counter+= min(b[i],a[0]);
                                swap(b[i],a[j+1]);
                                swap_counter+=min(b[i],a[j+1]);
                            }
                            else{
                                swap(b[i],a[j+1]);
                                swap_counter+= min(b[i],a[j+1]);
                            }
                        }
                        else {
                            //Swap b[i],a[j+1]
                            //Using b[0]
                            if(min(b[i],a[j+1])>b[0]*2) {
                                swap(b[0],a[j+1]);
                                swap_counter+=min(b[0],a[j+1]);
                                swap(b[i],a[j+1]);
                                swap_counter+=min(b[i],a[j+1]);

                                // swap(b[i],a[0]);
                                // swap_counter+= min(b[i],a[0]);
                                // swap(b[i],a[j+1]);
                                // swap_counter+=min(b[i],a[j+1]);
                            }
                            else{
                                swap(b[i],a[j+1]);
                                swap_counter+= min(b[i],a[j+1]);
                            }
                        }
                        
                    }

                if(flag==0) {
                    if(b[i]==b[i+1]) {
                    //Swap a[i] && b[i+1]
                    //using b[0]
                    flag=1;
                    if(minimum==b[0]) {
                        if(min(a[i],b[i+1])>b[0]*2){
                            swap(b[0],a[i]);
                            swap_counter+=min(b[0],a[i]);
                            swap(a[i],b[i+1]);
                            swap_counter+= min(a[i],b[i+1]);
                        }
                        else
                        {
                            swap(a[i],b[i+1]);
                            swap_counter+=min(a[i],b[i+1]);
                        }
                    }
                    else{
                        //Swap a[i] && b[i+1]
                        //Using a[0];
                        if(min(a[i],b[i+1])>a[0]*2){
                            swap(a[0],b[j+1]);
                            swap_counter+= min(a[0],b[j+1]);
                            swap(b[i+1], a[i]);
                            swap_counter+= min(a[i],b[i+1]);
                            
                            // swap(b[0],a[i]);
                            // swap_counter+=min(b[0],a[i]);
                            // swap(a[i],b[i+1]);
                            // swap_counter+= min(a[i],b[i+1]);
                        }
                        else
                        {
                            swap(a[i],b[i+1]);
                            swap_counter+=min(a[i],b[i+1]);
                        }
                    }
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

            if(master_flag==0) {
                break;
            }
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