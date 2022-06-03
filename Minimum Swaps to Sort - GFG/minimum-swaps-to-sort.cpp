// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int> tmp(nums.begin(),nums.end());
	    sort(tmp.begin(),tmp.end());
	    int ans = 0, n = nums.size();
	    map<int,int> mp;
	    for(int i=0;i<n;i++)mp[nums[i]] = i;
	    for(int i=0;i<n;i++)
	        if(tmp[i]!=nums[i]){
	            ans++;
	            int t = nums[i];
	            swap(nums[i],nums[mp[tmp[i]]]);
	            mp[t] = mp[tmp[i]];
	            mp[tmp[i]] = i;
	        }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends