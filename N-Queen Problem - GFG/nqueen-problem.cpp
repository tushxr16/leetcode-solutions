//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    
    bool isSafe(int r, int c, int n, vector<vector<int>> &grid){
        for(int i=0;i<=c;i++){
            if(grid[r][i]==1){
                return false;
            }
        }
        for(int i=r, j=c; i>=0 && j>=0; i--,j--){
            if(grid[i][j]==1){
                return false;
            }
        }
        for(int i=r, j=c; i<n && j>=0; i++,j--){
            if(grid[i][j]==1){
                return false;
            }
        }
        return true;
    }
    
    void solve(vector<int> v, vector<vector<int>> &ans, int n, int col, vector<vector<int>> &grid){
        if(col==n){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,col,n,grid)){
                grid[i][col] = 1;
                v.push_back(i+1);
                solve(v,ans,n,col+1,grid);
                v.pop_back();
                grid[i][col] = 0;
            }
        }
        return;
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<vector<int>> grid(n,vector<int>(n,0));
        vector<int> v;
        solve(v,ans,n,0,grid);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends