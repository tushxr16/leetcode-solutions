//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        
        int n = beginWord.size();
        
        vector<vector<string>> ans;
        unordered_set<string> mp;
        
        for(string s: wordList)
            mp.insert(s);
        
        mp.erase(beginWord);
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        while(!q.empty()){
        
            int q_size = q.size();
            bool flag = false;
            
            for(int i=0;i<q_size;i++){
                
                vector<string> v = q.front();
                string str = v.back();
                q.pop();
                
                if(str==endWord){
                    ans.push_back(v);
                    flag = true;
                }
                
                mp.erase(str);
                
                for(int i=0;i<n;i++){
                    char temp = str[i];
                    for(char c='a';c<='z';c++){
                        str[i] = c;
                        if(mp.find(str)!=mp.end()){
                            v.push_back(str);
                            q.push(v);
                            v.pop_back();
                        }
                    }
                    str[i] = temp;
                }
            }
            if(flag){
                return ans;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends