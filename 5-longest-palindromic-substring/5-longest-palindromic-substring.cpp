class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 0;
        string ans;
        for(int i=0;i<n;i++){
            int j = i, k = i;
            while(j>=0 && s[i]==s[j]){
                j--;
            }
            while(k<n && s[i]==s[k]){
                k++;
            }
            while(j>=0 && k<n && s[j]==s[k]){
                j--;k++;
            }
            if(k-j-1>maxLen){
                maxLen = k-j-1;
                ans = s.substr(j+1,maxLen);
            }
        }
        return ans;
    }
};