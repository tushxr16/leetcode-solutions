// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int l[n] = {0}, mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx,arr[i]);
            l[i] = mx;
        }
        mx = 0;
        for(int i=n-1;i>-1;i--){
            mx = max(mx,arr[i]);
            l[i] = min(mx,l[i]);
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            if(l[i]-arr[i]>0){
                ans+=l[i]-arr[i];
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