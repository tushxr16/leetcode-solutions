// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int l[n] = {0}, mx = arr[0];
        for(int i=0;i<n;i++){
            mx = max(mx,arr[i]);
            l[i] = mx;
        }
        mx = arr[n-1];
        for(int i=0;i<n;i++){
            mx = max(mx,arr[n-i-1]);
            l[n-i-1] = min(mx,l[n-i-1]);
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            if(l[i]-arr[i]>0){
                ans+=(l[i]-arr[i]);
            }
        }
        return ans;
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