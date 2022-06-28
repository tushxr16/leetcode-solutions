// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void permute(set<string> &st, string s, int i){
	        if(i==s.size()){
	            st.insert(s);
	        }
	        for(int j=i;j<s.size();j++){
	            swap(s[i],s[j]);
	            permute(st,s,i+1);
	            swap(s[i],s[j]);
	        }
	        return;
	    }
		vector<string>find_permutation(string S)
		{
		    set<string> s;
		    permute(s,S,0);
		    vector<string> ans(s.begin(),s.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends