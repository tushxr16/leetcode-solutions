//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        int lo = 0, hi = v.size()-1, midF=-1, midL=-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(v[mid]>x){
                hi = mid-1;
            }else if(v[mid]<x){
                lo = mid+1;
            }else{
                midF = mid;
                hi = mid-1;
            }
        }
        lo = 0, hi = v.size()-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(v[mid]>x){
                hi = mid-1;
            }else if(v[mid]<x){
                lo = mid+1;
            }else{
                midL = mid;
                lo = mid+1;
            }
        }
        return {midF,midL};
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