// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        if(n<2)
            return arr;
        int lastInc = -1, i = 1;
        while(i<n){
            if(arr[i]>arr[i-1])
                lastInc = i;
            i++;
        }
        if(lastInc==-1){
            for(int i=0;i<n/2;i++)
                swap(arr[i],arr[n-i-1]);
            return arr;
        }
        int index = lastInc;
        for(int i=lastInc;i<n;i++){
            if(arr[i]<arr[index] && arr[i]>arr[lastInc-1])
                index = i;
        }
        swap(arr[lastInc-1],arr[index]);
        sort(arr.begin()+lastInc,arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends