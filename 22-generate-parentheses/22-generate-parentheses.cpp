class Solution {
public:
    bool checkParanthesis(string s, int n){
        stack<char> st;
        for(int i=0;i<2*n;i++){
            if(s[i]=='('){
                st.push('(');
            }else{
                if(st.empty()){
                    return false;
                }else if(st.top()!='('){
                    return false;
                }else{
                    st.pop();
                }
            }
        }
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        for(int i=0;i<n;i++){
            s.push_back('(');
        }
        for(int i=0;i<n;i++){
            s.push_back(')');
        }
        do{
            if(checkParanthesis(s,n)){
                ans.push_back(s);
            }
        }while(next_permutation(s.begin(),s.end()));
        return ans;
    }
};