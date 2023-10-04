//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++
class comp {
    public:
        bool operator() (pair<int,int> p1, pair<int,int> p2) {
            if(p1.first > p2.first){
                return true;
            }else if(p1.first==p2.first){
                return p1.second>p2.second;
            }else{
                return false;
            }
        }
};

class Solution{
    public: 
        vector<int> Kclosest(vector<int>arr, int n, int x, int k) {
            priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
            vector<int> ans;
            
            for(int i=0;i<n;i++){
                pq.push({abs(x-arr[i]),arr[i]});
            }
            
            while(k--){
                ans.push_back(pq.top().second);
                pq.pop();
            }
            sort(ans.begin(),ans.end());
            return ans;
        }  
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,k;
		cin>>n>>x>>k; 
		vector <int> array(n);
		for (int i = 0; i < n; ++i)
			cin>>array[i];
        
        Solution obj;
		vector <int> result = obj.Kclosest(array, n, x, k); 
		for (int i = 0; i < result.size(); ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}

	return 0; 
} 




// } Driver Code Ends