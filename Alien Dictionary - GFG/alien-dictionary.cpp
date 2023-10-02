//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void dfs(char x, unordered_map<char,vector<char>> &adj, unordered_map<char,bool> &vis, stack<char> &st){
        vis[x] = true;
        
        for(char i: adj[x]){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        st.push(x);
        return;
    }
    string findOrder(string dict[], int n, int k) {
        unordered_map<char,vector<char>> adj;
        unordered_map<char, bool> vis;
        
        for(int k=1;k<n;k++){
            string word1 = dict[k-1], word2 = dict[k];
            int n = word1.size(), m = word2.size(), i = 0, j = 0;
            
            while(i<n && j<m){
                if(word1[i]==word2[j]){
                    i++;j++;
                }else{
                    adj[word1[i]].push_back(word2[j]);
                    vis[word1[i]] = false;
                    vis[word2[j]] = false;
                    break;
                }
            }
            
        }
        
        stack<char> st;
        
        for(pair<char, bool> p: vis){
            if(!vis[p.first]){
                dfs(p.first,adj,vis,st);
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends