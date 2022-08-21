class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, n = s.size(), curr = 0;
        for(int i=0;i<n;i++){
            
            if(s[i]==')')
                continue;
            curr = 0;
            
            for(int j=i;j<n;j++){
                if(s[j]=='(')
                    curr++;
                else
                    curr--;
                if(curr<0)
                    break;
                if(curr==0)
                    ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};