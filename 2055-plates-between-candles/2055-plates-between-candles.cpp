class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        
        vector<int> ans;
        vector<int> left(n,-1), right(n,-1), prefix;
        prefix.push_back(0);
        
        for(int i=0;i<n;i++){
            if(s[i]=='|'){
                left[i] = i;
            }else{
                if(i>0){
                    left[i] = left[i-1];
                }
            }
        }
        
        for(int i=n-1;i>=0;i--){
            if(s[i]=='|'){
                right[i] = i;
            }else{
                if(i<n-1){
                    right[i] = right[i+1];
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                prefix.push_back(1+prefix[prefix.size()-1]);
            }else{
                prefix.push_back(prefix[prefix.size()-1]);
            }
        }
        
        for(int i=0;i<queries.size();i++){
            int r = queries[i][1], l = queries[i][0];
            r = left[r];
            l = right[l];
            
            if(l>r || l<0){
                ans.push_back(0);
            }
            else{
                int n = prefix[r+1];
                int m = prefix[l];
                ans.push_back(n-m);
            }
        }
        return ans;
    }
};