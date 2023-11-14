//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int a[MAX][MAX], int n, int m) {
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==1)
                    a[i][j] += a[i-1][j];
            }
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            stack<int> st;
            vector<int> left(m), right(m);
            for(int j=0;j<m;j++){
                if(st.empty()){
                    left[j] = 0;
                    st.push(j);
                }else{
                    while(!st.empty() && a[i][st.top()]>=a[i][j]){
                        st.pop();
                    }
                    left[j] = st.empty()?0:st.top()+1;
                    st.push(j);
                }
            }
            while(!st.empty())
                st.pop();
            for(int j=m-1;j>=0;j--){
                if(st.empty()){
                    right[j] = m-1;
                    st.push(j);
                }else{
                    while(!st.empty() && a[i][st.top()]>=a[i][j]){
                        st.pop();
                    }
                    right[j] = st.empty()?m-1:st.top()-1;
                    st.push(j);
                }
            }
            for(int j=0;j<m;j++){
                ans = max(ans,a[i][j]*(right[j]-left[j]+1));
            }
        }
        return ans;
    }
};




//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends