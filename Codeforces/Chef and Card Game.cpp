//Template
#include <bits/stdc++.h>
typedef long long ll; 
using namespace std;

int sum_of_digits(int n) {
    int sum = 0; 
    while (n != 0) 
    {
     sum = sum + n % 10; 
     n = n/10; 
    }  
 return sum; 
 } 


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        
        ll points_chef=0;
        ll points_monty=0;
        while(n--) {
            ll sum_chef=0;
            ll sum_monty=0;
            ll a;int b;
            cin>>a>>b;
            // cout<<sum_of_digits(a)<<" "<<sum_of_digits(b)<<endl;
            sum_chef = sum_of_digits(a);
            sum_monty = sum_of_digits(b);
            if(sum_monty>sum_chef) {
                points_monty++;
            }
            else if(sum_chef>sum_monty) {
                points_chef++;
            }
            else {
                points_chef++;
                points_monty++;
            }
        }
        if(points_chef > points_monty) {
            cout<<"0"<<" "<<points_chef<<endl;
        }
        else if(points_chef< points_monty) {
            cout<<"1"<<" "<<points_monty<<endl;
        }
        else {
            cout<<"2"<<" "<<points_chef<<endl;
        }
    }
    return 0;
}