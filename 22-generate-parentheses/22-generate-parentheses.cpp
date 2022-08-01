class Solution {
public:
    void backTracking(vector<string> &ans, string curr, int open, int close, int max){
        if(curr.size() == max*2){
            ans.push_back(curr);
            return;
        }
        if(open<max){
            backTracking(ans,curr + '(', open + 1, close, max);
        }
        if(close<open){
            backTracking(ans,curr + ')', open, close + 1, max);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backTracking(ans,"",0,0,n);
        return ans;
    }
};