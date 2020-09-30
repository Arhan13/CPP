//Template
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll; 
using namespace std;
int main(){
ios::sync_with_stdio(0);cin.tie(0);
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        ll q;cin>>q;
        ll heights[n];
        ll tastes[n];
        for(int i=1;i<=n;i++) {
            cin>>heights[i];
        }
        for(int i=1;i<=n;i++) {
            cin>>tastes[i];
        }
        while(q--) {
            int type;cin>>type;
            if(type==1) {
                ll index;cin>>index;
                ll new_taste;cin>>new_taste;
                tastes[index] = new_taste;
            }
            else if(type==2) {
                ll start;cin>>start;
                ll end;cin>>end;
                ll master_flag=0;
                ll taste_sum=0;
                vector <ll> new_heights;
                if(heights[start]>heights[end]) {
                    //Case 1
                    if(start>end) {
                        for(ll i=start-1;i>end;i--) {
                            new_heights.push_back(heights[i]);
                        }
                        sort(new_heights.begin(),new_heights.end());
                        if(new_heights[0]>=heights[start]) {
                            master_flag=1;
                        }
                        ll nh_index=0;
                    if(master_flag==0) {
                        for(ll i=start-1;i>end;i--) {
                            int flag=1;
                            if(heights[i]==new_heights[nh_index]) {
                                if(nh_index==new_heights.size()-1 &&
                                    new_heights[nh_index]>heights[end] &&
                                    new_heights[nh_index]<heights[start]) {
                                        taste_sum+=tastes[i];
                                    }
                                else {
                                    continue;
                                }
                                if(nh_index+1<=new_heights.size()-1 && 
                                    new_heights[nh_index]==new_heights[nh_index+1]) {
                                        nh_index++;
                                    }
                                else if(nh_index+1<=new_heights.size()-1 && 
                                    new_heights[nh_index]!=new_heights[nh_index+1] &&
                                    new_heights[nh_index]>heights[end] &&
                                    new_heights[nh_index]<heights[start]) {
                                            taste_sum+=tastes[i];
                                    }
                            }
                        }
                        taste_sum += tastes[start];
                        taste_sum += tastes[end];
                    }
                    else {
                        taste_sum=-1;
                    }
                    }
                    //Case 1 ends

                    //Case 2
                    else if(start<end) {
                        for(ll i = start+1;i<end;i++) {
                            new_heights.push_back(heights[i]);
                        }
                        sort(new_heights.begin(),new_heights.end());
                        if(new_heights[0]>=heights[start]) {
                            master_flag=1;
                        }
                        ll nh_index=0;
                    if(master_flag==0) {
                        for(ll i=start+1;i<end;i++) {
                            int flag=1;
                            if(heights[i]==new_heights[nh_index]) {
                                if(nh_index==new_heights.size()-1 &&
                                    new_heights[nh_index]>heights[end] &&
                                    new_heights[nh_index]<heights[start]) {
                                        taste_sum+=tastes[i];
                                    }
                                else [
                                    continue;
                                ]
                                if(nh_index+1<=new_heights.size()-1 && 
                                    new_heights[nh_index]==new_heights[nh_index+1]) {
                                        nh_index++;
                                    }
                                else if(nh_index+1<=new_heights.size()-1 && 
                                    new_heights[nh_index]!=new_heights[nh_index+1] &&
                                    new_heights[nh_index]>heights[end] &&
                                    new_heights[nh_index]<heights[start]) {
                                            taste_sum+=tastes[i];
                                    }
                            }
                        }
                        taste_sum += tastes[start];
                        taste_sum += tastes[end];
                    }
                    else {
                        taste_sum=-1;
                    }
                    }
                    //Case 2 ends

                    //Case 3 starts
                    else {
                        taste_sum = tastes[start];
                    }
                    //Case 3 ends

                }
                else {
                    master_flag=1;
                    taste_sum = -1;
                }

                if(master_flag==1) {
                    cout<<"-1"<<endl;
                }
                else if (master_flag==0) {
                    cout<<taste_sum<<endl;
                }
            }
        }
    }
    return 0;

}