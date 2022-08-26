class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push({s[i],i});
            }else if(s[i]==')'){
                if(st.empty()){
                    st.push({s[i],i});
                }else{
                    if(st.top().first=='('){
                        st.pop();
                    }else{
                        st.push({s[i],i});
                    }
                }
            }
        }
        while(!st.empty()){
            s.erase(s.begin()+st.top().second,s.begin()+st.top().second+1);
            st.pop();
        }
        return s;
    }
};