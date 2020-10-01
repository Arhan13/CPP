#include <bits/stdc++.h>
using namespace std;
  int upper_bound(int a[],int n,int key)
  {
      int s=0;
      int e=n-1;
       int ans=-1;
   //using binary search 
      while(s<=e)
      {
          int mid=(s+e)/2;
      
      if(a[mid]==key)
      {
          ans=mid;
          s=mid+1;      //change

      }
      else if (a[mid]>key)
      {
          e=mid-1;

      }
         else{
         
         s=mid+1;
         }
  }
   return ans;

}


 int lower_bound(int a[],int n,int key)
  {
      int s=0;
      int e=n-1;
       int ans=-1;
 //using binary search 
      while(s<=e)
      {
          int mid=(s+e)/2;
      
      if(a[mid]==key)
      {
          ans=mid;
          e=mid-1;  //change

      }
      else if(a[mid]>key)
      {
          e=mid-1;

      }
         else{
         
         s=mid+1;
         }
  }
   return ans;

}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
   int t;
   cin>>t;
   while(t--)
   {
    int key;
    cin>>key;
   
   int ans = lower_bound(a,n,key); //first calculate lower_bound
   cout<<ans<<" ";
    ans= upper_bound(a,n,key);  //then calculate upper_bound
   cout<<ans;
   cout<<endl;
   ans=0;
   }
   return 0;

}
