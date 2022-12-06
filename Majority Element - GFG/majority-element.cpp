//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int n)
    {
        int maj_index = 0, cnt = 0;
        for(int i=0;i<n;i++){
            if(a[maj_index]==a[i]){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt==0){
                maj_index = i;
                cnt++;
            }
        }
        cnt = 0;
        for(int i=0;i<n;i++){
            if(a[maj_index]==a[i]){
                cnt++;
            }
        }
        if(cnt>n/2){
            return a[maj_index];
        }else{
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends