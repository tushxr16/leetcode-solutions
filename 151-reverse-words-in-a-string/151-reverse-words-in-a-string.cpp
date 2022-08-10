class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans;
        for(int i=0;i<n;i++){
            string t;
            for(int j=i;j<n && s[j]!=' ';j++,i++){
                t.push_back(s[j]);
            }
            if(t.size())
                ans = t + " " + ans;
        }
        ans.pop_back();
        return ans;
    }
};