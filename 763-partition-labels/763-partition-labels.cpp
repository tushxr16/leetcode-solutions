class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res,posi(26, 0);  
        for (int i=0;i<s.size();i++)posi[s[i]-'a']=i;
        for (int i=0,idx=-1,last_i=0;i<s.size();i++){
            idx=max(idx,posi[s[i]-'a']);
            if(idx==i)
                res.push_back(i-exchange(last_i,i+1)+1);
        }
        return res;
    }
};