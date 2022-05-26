// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void findPathUtil(int x, int y, int n, 
        vector<vector<int>> &m, string tmp, vector<string> &ans){

        if(x<0 || y<0 || x>n-1 || y>n-1 || m[x][y]==0)
            return;
        if(x==n-1 && y==n-1){
            ans.push_back(tmp);
            return;
        }
        m[x][y]=0;
        findPathUtil(x+1,y,n,m,tmp+'D',ans);
        findPathUtil(x,y-1,n,m,tmp+'L',ans);
        findPathUtil(x,y+1,n,m,tmp+'R',ans);
        findPathUtil(x-1,y,n,m,tmp+'U',ans);
        m[x][y]=1;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string tmp = "";
        findPathUtil(0,0,m.size(),m,tmp,ans);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends