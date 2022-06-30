// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            int r = 0, max_row = 0, max_val = -1, idx = 0;
            for(int i=0;i<N;i++){
                if(Mat[i][0]==1)
                    return i;
                int cnt = M;
                int lo = 0, hi = M-1, mid;
                while(lo<=hi){
                    mid = (lo+hi)/2;
                    if(Mat[i][mid]==1){
                        cnt = mid;
                        hi = mid-1;
                    }else{
                        lo = mid+1;
                    }
                }
                idx = M-cnt;
                if(idx>max_val){
                        max_row = i;
                        max_val = idx;
                }
            }
            return max_row;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends