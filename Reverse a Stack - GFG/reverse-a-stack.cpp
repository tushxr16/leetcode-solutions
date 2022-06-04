// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void ReverseUtil(stack<int> st, vector<int> &ans){
        if(st.size()==0)return;
        int tp = st.top();
        st.pop();
        ans.push_back(tp);
        ReverseUtil(st,ans);
        return;
    }
    vector<int> Reverse(stack<int> St){
        vector<int> ans;
        ReverseUtil(St,ans);
        return ans;
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends