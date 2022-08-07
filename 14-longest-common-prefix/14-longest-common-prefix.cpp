class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = INT_MAX, n = strs.size();
        for(int i=1;i<n;i++){
            
            int j = 0, m = min(strs[i].size(),strs[i-1].size());
            
            while(j<min(m,idx) && strs[i][j] == strs[i-1][j]){
                j++;
            }
            
            idx = min(idx,j);
        }
        return strs[0].substr(0,idx);
    }
};