// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int A[], int N, int M, int mid){
        int sum = 0, studentRequired = 1;
        for(int i=0;i<N;i++){
            if(A[i]>mid)
                return false;
            if(A[i]+sum>mid){
                sum = A[i];
                studentRequired++;
                if(studentRequired>M){
                    return false;
                }
            }else{
                sum+=A[i];
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        if(N<M){
            return -1;
        }
        
        int sum = 0, ans = INT_MAX;
        for(int i=0;i<N;i++)
            sum+=A[i];
        
        int start = 0, end = sum, mid;
        while(start<=end){
            mid = (start+end)/2;
            if(isPossible(A,N,M,mid)){
                end = mid-1;
                ans = min(ans,mid);
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends