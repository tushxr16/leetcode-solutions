//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int, vector<int>, greater<int>> pq_min;
    priority_queue<int> pq_max;
    
    void insertHeap(int &x){
        if(pq_max.empty() || pq_max.top() >= x){
            pq_max.push(x);
        }else{
            pq_min.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps(){
        if(pq_min.size()>pq_max.size()){
            pq_max.push(pq_min.top());
            pq_min.pop();
        }else if(pq_min.size()+1<pq_max.size()){
            pq_min.push(pq_max.top());
            pq_max.pop();
        }
    }
    
    //Function to return Median.
    double getMedian(){
        double ans = (double)pq_max.top();
        if(pq_min.size()==pq_max.size()){
            ans += (double)pq_min.top();
            ans = ans/2.0;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends