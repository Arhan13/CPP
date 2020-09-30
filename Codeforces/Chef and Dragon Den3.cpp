//Template
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll; 
using namespace std;

float gradient_calculator(ll high, ll low, ll start, ll end) {
    ll value_diff = high-low;
    ll distance_diff = abs(start-end);
    float gradient = (float)value_diff/distance_diff;
    // cout<<gradient<<endl;
    // float max_height = height[start_position];
    return gradient;
}
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

                // ll value_diff = height[start_position]-height[end_position];
                // ll distance_diff = abs(start_position-end_position);
                // float gradient = (float)value_diff/distance_diff;
                
                float gradient = gradient_calculator(height[start_position],height[end_position],start_position,end_position);
                float max_height = height[start_position];

                flag=1;
                    if(start_position>end_position && abs(start_position-end_position)>1) {
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

                        ll height_start_pos=start_position-1;
                        while(ih[ih_index]!=height[height_start_pos]){
                            height_start_pos--;
                            // cout<<height_start_pos<<endl;
                        }
                        if(ih[ih_index]<height[start_position]&&ih[ih_index]>height[end_position]) {
                            gradient = gradient_calculator(height[start_position],ih[ih_index],start_position,height_start_pos);
                            max_height = height[start_position];
                        }
                        else if(ih[ih_index]<=height[end_position]) {
                            continue;
                        }
                        else {
                            flag=0;
                        }



                        for(ll i = start_position-1;i>end_position;i--) {
                            if(i>end_position) {
                                max_height-= gradient;
                                // cout<<max_height<<endl;
                            }
                            if(ih[ih_index]>=height[start_position]) {
                                // cout<<"Im here"<<endl;
                                flag=0;
                                break;
                            }
                            if(ih[ih_index]<=height[end_position]) {
                                // cout<<"Im here"<<endl;
                                break;
                            }
                            if(ih[ih_index]>max_height) {
                                // cout<<max_height<<endl;
                                // cout<<"Im here"<<endl;
                                // cout<<height[i]<<endl;
                                // cout<<ih[ih_index]<<endl;
                                flag=0;
                                break;
                            }
                            if(height[i]==ih[ih_index] && ih[ih_index]<height[start_position] && ih[ih_index]>height[end_position] && ih[ih_index]<=max_height) {
                                ll value = ih[ih_index];
                                ll counter=0;
                                for(int i=ih_index+1;i<ih.size();i++) {
                                    if(ih[i]==value) {
                                        counter++;
                                    }
                                }
                                if(counter==0) {
                                    total_taste+=taste[i];
                                    gradient = gradient_calculator(ih[ih_index],height[end_position],i,end_position);
                                    max_height = ih[ih_index];
                                    ih_index++;
                                }
                                else {
                                    break;
                                }
                            }
                    }
                    if(flag==1){
                        total_taste+= taste[end_position];
                    }
                }
                else if(start_position<end_position && abs(start_position-end_position)>1) {
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
                        
                        ll height_start_pos=start_position+1;
                        while(ih[ih_index]!=height[height_start_pos] && height_start_pos<end_position){
                            height_start_pos++;
                            // cout<<height_start_pos<<endl;
                        }
                        if(ih[ih_index]<height[start_position]&&ih[ih_index]>height[end_position]) {
                            gradient = gradient_calculator(height[start_position],ih[ih_index],start_position,height_start_pos);
                            max_height = height[start_position];
                        }
                        else if(ih[ih_index]<=height[end_position]) {
                            continue;
                        }
                        else {
                            flag=0;
                        }
                    for(ll i = start_position+1; i < end_position;i++) {
                        if(i<end_position) {
                            max_height-= gradient;
                        }
                        if(ih[ih_index]<=height[end_position]) {
                            break;
                        }
                        if(ih[ih_index]>=height[start_position]) {
                            flag=0;
                            break;
                        }
                        if(ih[i]>max_height || height[i]>max_height) {
                                flag=0;
                                break;
                        }
                        if(height[i]==ih[ih_index] && ih[ih_index]<height[start_position] && ih[ih_index]>height[end_position] && ih[ih_index]<=max_height) {
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
                                gradient = gradient_calculator(ih[ih_index],height[end_position],i,end_position);
                                max_height = ih[ih_index];
                                ih_index++;
                            }
                            else {
                                break;
                            }   
                        }
                    }
                    if(flag==1){
                        total_taste+= taste[end_position];
                    }
                }
                else if(abs(start_position-end_position)==1) {
                    total_taste = taste[start_position]+taste[end_position];
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