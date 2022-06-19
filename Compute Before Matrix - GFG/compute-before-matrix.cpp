// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> computeBeforeMatrix(int N, int M, vector<vector<int>> after){
        
        for(int i=N-1;i>0;i--){
            for(int j=M-1;j>0;j--){
                after[i][j] -= (after[i-1][j] + after[i][j-1] - after[i-1][j-1]);
            }
        }
        
        for(int i=M-1;i>0;i--)
            after[0][i] = after[0][i] - after[0][i-1];
        for(int i=N-1;i>0;i--)
            after[i][0] = after[i][0] - after[i-1][0];
        
        return after;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M; 
        vector<vector<int>> after(N,vector<int>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>after[i][j];
            }
        } 
        Solution obj;
        vector<vector<int>> before=obj.computeBeforeMatrix(N,M,after); 
        for(int i=0;i<before.size();i++){
            for(int j=0;j<before[i].size();j++){
                cout<<before[i][j]<<' ';
            } 
            cout<<endl;
        }
    }
}  // } Driver Code Ends