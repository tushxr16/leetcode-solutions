// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long count = 0;
    void conquer(long long v[], long long lo, long long mid, long long hi){
        long long merged[hi-lo+1] = {0};
        long long idx1 = lo, idx2 = mid+1, k = 0;
        while(idx1<=mid && idx2<=hi){
            if(v[idx1]<=v[idx2]){
                merged[k++] = v[idx1++];
            }else{
                merged[k++] = v[idx2++];
                count+=(mid-idx1+1);
            }
        }
        
        while(idx1<=mid){
            merged[k++] = v[idx1++];
        }
        
        while(idx2<=hi){
            merged[k++] = v[idx2++];
        }
        for(long long i=0;i<(hi-lo+1);i++)
            v[i+lo] = merged[i];
        return;
    }
    void divide(long long v[], long long lo, long long hi){
        if(lo<hi){
            long long mid = (lo+hi)/2;
            divide(v,lo,mid);
            divide(v,mid+1,hi);
            conquer(v,lo,mid,hi);
        }
        return;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        divide(arr,0,N-1);
        return count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends