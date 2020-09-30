//Template
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll; 
using namespace std;
int main(){
ios::sync_with_stdio(0);cin.tie(0);
    ll t;cin>>t;
    while(t--) {
        // for(int i=0;i<n;i++) {
        //     if(a[i]==b[i]) {
        //         continue;
        //     }
        //     else if(a[i]>b[i]) {
        //         int j=i; int flag=0;
        //         for(int j=i+1;j<n;j++) {
        //             if(a[i]==b[j]) {
        //                 swap()
        //                 int temp = a[i];
        //                 a[i] = b[j];
        //                 b[j] = temp;
        //                 flag=1;
        //                 swap_counter += min(a[i],b[j]);
        //                 break;
        //             }
        //         }
        //         if(flag==0) {
        //             if(a[i]==a[i+1]) {
        //                 // b[i] && a[i+1]
        //                 flag=1;
        //                 swap(a[0],b[i]);
        //                 swap_counter += min(a[0],b[i]);
        //                 swap(b[i],a[i+1]);
        //                 swap_counter += min(b[i],a[i+1]);
                        
        //             }
        //         }
                
        //         if(flag==1) {
        //             master_flag=1;
        //             sort(a,a+n);
        //             sort(b,b+n);
        //         }
        //         else {
        //             master_flag=0;
        //             break;
        //         }
        //     }

        //     else if(a[i]<b[i]) {
        //         int j=i; int flag=0;
        //         for(int j=i+1;j<n;j++) {
        //             if(b[i]==a[j]) {
        //                 int temp = b[i];
        //                 b[i] = a[j];
        //                 a[j] = temp;
        //                 flag=1;
        //                 swap_counter += min(b[i],a[j]);
        //                 break;
        //             }
        //         }
        //         if(flag==0) {
        //             if(b[i]==b[i+1]) {
        //                 //Swap a[i] && b[i+1]
        //                 flag=1;
        //                 swap(b[0],a[i]);
        //                 swap_counter+=min(b[0],a[i]);
        //                 swap(a[i],b[i+1]);
        //                 swap_counter(a[i],b[i+1]);
        //                 // swap_counter+= min(a[i],b[i+1]);
        //                 // int temp = a[i];
        //                 // a[i] = b[i+1];
        //                 // b[i+1] = temp;
        //             }
        //         }
        //         if(flag==1) {
        //             master_flag=1;
        //             sort(a,a+n);
        //             sort(b,b+n);
        //         }
        //         else {
        //             master_flag=0;
        //             break;
        //         }
        //     }

        //     if(master_flag==0) {
        //         break;
        //     }
        // }
        // if(master_flag==0) {
        //     cout<<"-1"<<endl;
        // }
        // else if(master_flag==1) {
        //     cout<<swap_counter<<endl;
        // }
        ll n;
        cin>>n;
        ll a[n], b[n];
        int master_flag=1;
        int swap_counter=0;
        unordered_map<ll,ll>main_map;
        vector<ll> array_a_vector={};
        vector<ll> array_b_vector={};
        for(int i=0;i<n;i++) {
            cin>>a[i];
            main_map[a[i]]++;
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
            main_map[b[i]]++;
        }

        sort(a,a+n);
        sort(b,b+n);
        ll minimum = min(a[0],b[0]);

        // map<ll, ll>::iterator itr;
        unordered_map<ll,ll> required_map1;
        unordered_map<ll,ll> required_map2;
        // for (itr = main_map.begin(); itr != main_map.end(); ++itr) {
        //     if(itr.second %2 == 1) {
        //         master_flag=0;
        //         break;
        //     }
        //     else {
        //         extra_map1[itr.first] = (itr.second)/2;
        //     }
        // } 
        for (auto itr: main_map) {
            if(itr.second %2 == 1) {
                master_flag=0;
                break;
            }
            else {
                required_map1[itr.first] = (itr.second)/2;
            }
        } 
        
        if(master_flag==0) {
            cout<<"-1"<<endl;
        }
        else {
            required_map2 = required_map1;//Replica of map1;
            for(int i=0;i<n;i++) {
                if(required_map1[a[i]]) {
                    required_map1[a[i]]--;
                }
                else {
                    array_a_vector.push_back(a[i]);
                }
            }
            for(int i=0;i<n;i++) {
                if(required_map2[b[i]]) {
                    required_map2[b[i]]--;
                }
                else {
                    array_b_vector.push_back(b[i]);
                }
            }
            ll size_of_vectors = array_a_vector.size();

            sort(array_a_vector.begin(),array_a_vector.end());
            sort(array_b_vector.begin(),array_b_vector.end());
            reverse(array_b_vector.begin(),array_b_vector.end());

            if(size_of_vectors==0) {
                swap_counter=0;
                if(master_flag==1) {
                    cout<<swap_counter<<endl;
                }
                else {
                    cout<<"-1"<<endl;
                }
            }

            else {
                for(ll i=0;i<size_of_vectors;i++) {
                    swap_counter+= min(min(array_a_vector[i],array_b_vector[i]), 2*minimum);
                    //Because double swap with minimum element will give minimum cost in most of the cases
                }
                if(master_flag==1) {
                    cout<<swap_counter<<endl;
                }
                else {
                    cout<<"-1"<<endl;
                }
                
            }
        }

    }
    return 0;

}