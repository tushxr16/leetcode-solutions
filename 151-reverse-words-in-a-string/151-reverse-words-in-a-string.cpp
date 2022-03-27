class Solution {
public:
    string reverseWords(string s) {
        string ans="", tmp="";
        for(int i=s.size()-1;i>-1;i--){
            if(s[i]==' '){
                for(int j=tmp.size()-1;j>-1;j--)
                    ans.push_back(tmp[j]);
                if(tmp.size()!=0)
                    ans.push_back(' ');
                tmp.clear();
            }else
                tmp.push_back(s[i]);
        }
        for(int j=tmp.size()-1;j>-1;j--){
            if(tmp.size()!=0)
                ans.push_back(tmp[j]);
        }
        if(ans[ans.size()-1]==' ')ans.pop_back();
        return ans;
    }
};