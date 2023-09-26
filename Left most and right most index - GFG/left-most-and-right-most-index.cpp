//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        int n = v.size();
        int lo = 0, hi = n-1, p1 = -1, p2 = -1;
        
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(v[mid]>x){
                hi = mid-1;
            }else if(v[mid]<x){
                lo = mid+1;
            }else{
                p1 = mid;
                hi = mid-1;
            }
        }
        
        lo = 0, hi = n-1;
        
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(v[mid]>x){
                hi = mid-1;
            }else if(v[mid]<x){
                lo = mid+1;
            }else{
                p2 = mid;
                lo = mid+1;
            }
        }
        
        return {p1,p2};
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
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends