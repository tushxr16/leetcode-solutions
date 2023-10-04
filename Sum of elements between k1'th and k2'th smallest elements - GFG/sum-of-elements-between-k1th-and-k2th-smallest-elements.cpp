//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long n, long long k1, long long k2)
    {
        long long k = k2-k1-1, sum = 0;
        priority_queue<long long> pq;
        
        for(long long i=0;i<k2-1;i++){
            pq.push(A[i]);
        }
        
        for(long long i=k2-1;i<n;i++){
            pq.push(A[i]);
            pq.pop();
        }
        
        while(k--){
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
        
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends