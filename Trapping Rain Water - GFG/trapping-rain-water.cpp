// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int left[n],right[n];
        left[0]=arr[0];
        right[n-1]=arr[n-1];
        long long sum=0;
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],arr[i]);
            right[n-1-i]=max(right[n-i],arr[n-1-i]);
        }
        for(int i=0;i<n;i++){
            int tmp = min(left[i],right[i])-arr[i];
            sum +=(tmp>0)?tmp:0;
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends