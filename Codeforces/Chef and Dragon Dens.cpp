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
    ll n,q;cin>>n>>q;
    ll height[n],taste[n];
    for(ll i=1;i<=n;i++) {
        cin>>height[i];
    }
    for(ll i=1;i<=n;i++) {
        cin>>taste[i];
    }
    long long total_taste=0;
    long long type,height_position,updated_taste,start_position,end_position;
    while(q--) {
        int flag=1;
        cin>>type;
        total_taste=0;
        if(type==1) {
            cin>>height_position>>updated_taste;
            taste[height_position] = updated_taste;
        }
        else if(type==2) {
            flag=1;
            cin>>start_position>>end_position;
            total_taste = taste[start_position];
            if(height[start_position]>=height[end_position]) {
                flag=1;
                    if(start_position>end_position) {
                    for(ll i = start_position;i>end_position;i--) {
                        if(height[i]>=height[i-1] && height[i-1]>=height[end_position]) {
                            total_taste+=taste[i-1];
                        }
                        else if(height[i]<height[i+1]) {
                            flag=0;
                        }
                        else {
                            // cout<<"-1"<<endl;
                            continue;
                        }
                    }
                }
                else if(start_position<end_position) {
                    for(ll i = start_position; i < end_position;i++) {
                        if(height[i+1]<=height[i] && height[i+1]>=height[end_position]) {
                            total_taste+=taste[i+1];
                        }
                        else if (height[i+1]>height[i]){
                            flag=0;
                        }
                        else{
                            continue;
                        }
                    }
                }
                if(flag==0) {
                    cout<<"-1"<<endl;
                }
                else {
                    cout<<total_taste<<endl;
                }
            }
            // else if(height[start_position]==height[end_position]) {
            //     for(int )
            //     total_taste+= taste[end_position];
            //     cout<<total_taste<<endl;
            // }
            else
            {
                flag=0;
                cout<<"-1"<<endl;
            }
            // if(start_position>end_position) {
            //     for(ll i = start_position;i>end_position;i--) {
            //         if(height[i]>height[i-1]) {
            //             total_taste+=taste[i-1];
            //         }
            //         else {
            //             // cout<<"-1"<<endl;
            //             flag=0;
            //         }
            //     }
            // }
            // else if(start_position<end_position) {
            //     for(ll i = start_position; i < end_position;i++) {
            //         if(height[i+1]<height[i]) {
            //             total_taste+=taste[i+1];
            //         }
            //         else {
            //             // cout<<"-1"<<endl;
            //             flag=0;
            //         }
            //         if()
            //     }
            // }
            // if(flag==0) {
            //     cout<<"-1"<<endl;
            // }
            // else {
            //     cout<<total_taste<<endl;
            // }
        }
    }
    return 0;

}