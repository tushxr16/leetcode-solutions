// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int mx_left = arr[0], mx_right = arr[n-1];
        vector<int> submax_left(n,mx_left), submax_right(n,mx_right);
        for(int i=1;i<n;i++){
            if(mx_left<arr[i]){
                mx_left = arr[i];
            }
            submax_left[i] = mx_left;
            
            if(mx_right<arr[n-i-1]){
                mx_right = arr[n-i-1];
            }
            submax_right[n-i-1] = mx_right;
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += max(0,min(submax_left[i],submax_right[i])-arr[i]);
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