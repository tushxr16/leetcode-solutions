class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int start = -1;int maxi = 0;
        for (int i=0;i<s.size();i++) {
            if (mp.count(s[i])!=0) {
                start = max(start, mp[s[i]]);
            }
            mp[s[i]] = i;
            maxi=max(maxi,i-start);
        }
        return maxi;
    }
};