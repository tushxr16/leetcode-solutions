class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxL = 0;
        for(int i=0;i<s.size();i++) {
            if(st.size()>1 && s[i]==')' && s[st.top()]=='(') {
                st.pop();
                maxL=max(maxL,i-st.top());
            }
            else if(s[i]=='(') 
                st.push(i);
            else 
                st.top()=i;
        }
        return maxL;
    }
};