// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    int thirdLargest(int a[], int n)
    {
         if(n<3)
            return -1;
         int max1 = max(a[0],max(a[1],a[2])), max3 = min(a[0],min(a[1],a[2]));
         int max2 = a[0]+a[1]+a[2]-max1-max3;
         for(int i=3;i<n;i++){
             if(a[i]>max1){
                 max3 = max2;
                 max2 = max1;
                 max1 = a[i];
             }else if(a[i]>max2){
                 max3 = max2;
                 max2 = a[i];
             }else if(a[i]>max3){
                 max3 = a[i];
             }
         }
         return max3;
    }

};

// { Driver Code Starts.
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution obj;
	    cout<<obj.thirdLargest(a,n)<<endl;
    }
}     // } Driver Code Ends