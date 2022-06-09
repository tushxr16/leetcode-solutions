class Solution {
public:
    string simplifyPath(string path) {
        path+="/";
        stack<string> st;
        string s = "";
        for(int i=1;i<path.size();i++){
            if(path[i]=='/'){
                if(s==".."){
                    if(!st.empty())
                        st.pop();
                }
                else if(s!="" && s!="."){
                    st.push(s);
                }
                s="";
            }
            else
                s+=path[i];
        }
        
        while(!st.empty()){
            s = "/"+st.top()+s;
            st.pop();
        }
        if(s=="")return "/";
        return s;
    }
};