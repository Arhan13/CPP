//Template
#include <bits/stdc++.h>
#define endl "\n"
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
    long long total_taste;
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
            if(height[start_position]>height[end_position]) {
                flag=1;
                    if(start_position>end_position) {
                        vector<ll> ih={};
                        ih.clear();
                        for(ll i=start_position-1;i>=end_position+1;i--) {
                            ih.push_back(height[i]);
                        }
                        sort(ih.begin(),ih.end(),greater<ll>());
                        // for(int i=0;i<ih.size();i++) {
                        //     cout<<ih[i]<<" ";
                        // }
                        // cout<<endl;
                        ll ih_index=0;
                        for(ll i = start_position-1;i>end_position;i--) {
                            if(height[i]==ih[ih_index] && ih[ih_index]<height[start_position] && ih[ih_index]>height[end_position] ) {
                                ll value = ih[ih_index];
                                ll counter=0;
                                for(int i=ih_index+1;i<ih.size();i++) {
                                    if(ih[i]==value) {
                                        counter++;
                                    }
                                }
                                if(counter==0) {
                                    total_taste+=taste[i];
                                    ih_index++;
                                }
                                else {
                                    break;
                                }
                            }
                            else if(ih[ih_index]<=height[end_position]) {
                                break;
                            }
                            else if(ih[ih_index]>=height[start_position]) {
                                flag=0;
                                break;
                            }
                            else if(flag==0) {
                                break;
                            }
                            else {
                                continue;
                            }
                    }
                        if(flag==1){
                            total_taste+= taste[end_position];
                        }
                }
                else if(start_position<end_position) {
                        vector<ll> ih={};
                        ih.clear();
                        for(ll i=start_position+1;i<end_position;i++) {
                            ih.push_back(height[i]);
                        }
                        sort(ih.begin(),ih.end(),greater<ll>());
                        // for(int i=0;i<ih.size();i++) {
                        //     cout<<ih[i]<<" ";
                        // }
                        // cout<<endl;
                        ll ih_index=0;
                    for(ll i = start_position+1; i < end_position;i++) {
                        if(height[i]==ih[ih_index] && ih[ih_index]<height[start_position] && ih[ih_index]>height[end_position] ) {
                                // total_taste+=taste[i];
                                // ih_index++;
                                ll value = ih[ih_index];
                                ll counter=0;
                                for(int i=ih_index+1;i<ih.size();i++) {
                                    if(ih[i]==value) {
                                        counter++;
                                    }
                                }
                                if(counter==0) {
                                    total_taste+=taste[i];
                                    ih_index++;
                                }
                                else {
                                    break;
                                }
                            }
                            else if(ih[ih_index]<=height[end_position]) {
                                // continue;
                                break;
                            }
                            else if(ih[ih_index]>=height[start_position]) {
                                flag=0;
                            }
                            else if(flag==0) {
                                break;
                            }
                            else {
                                continue;
                            }
                        
                        // if(height[i+1]=<height[i] && height[i+1]>=height[end_position]) {
                        //     total_taste+=taste[i+1];
                        // }
                        // else if (height[i+1]>height[i]){
                        //     flag=0;
                        // }
                        // else{
                        //     continue;
                        // }
                    }
                    if(flag==1){
                        total_taste+= taste[end_position];
                    }
                }
                else if(start_position==end_position){
                    total_taste=taste[start_position];
                    flag=1;
                }
                if(flag==0) {
                    cout<<"-1"<<endl;
                }
                else {
                    cout<<total_taste<<endl;
                }
            }
            else
            {
                flag=0;
                cout<<"-1"<<endl;
            }
        }
    }
    return 0;

}