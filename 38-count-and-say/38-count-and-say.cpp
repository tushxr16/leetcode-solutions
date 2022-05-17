class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string s = countAndSay(n-1);
        string ret = "";
        int cnt = 1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1])cnt++;
            else {
                ret+=(to_string(cnt));
                ret.push_back(s[i-1]);
                cnt=1;
            }
        }
        ret+=(to_string(cnt));
        ret.push_back(s[s.size()-1]);
        return ret;
    }
};