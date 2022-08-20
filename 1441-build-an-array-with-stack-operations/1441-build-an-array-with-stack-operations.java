class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int sz = target.size(), cnt = 1;
        vector<string> ans;
        for(int i=0;i<sz;i++){
            if(target[i]!=cnt){
                i--;
                ans.push_back("Push");
                ans.push_back("Pop");
            }else{
                ans.push_back("Push");
            }
            cnt++;
        }
        return ans;
    }
};