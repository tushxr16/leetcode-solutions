class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n&1){
            for(int i=0;i<n;i++){
                ans.push_back(i-n/2);
            }
        }else{
            for(int i=0;i<n+1;i++){
                if((i-n/2)!=0)
                    ans.push_back(i-n/2);
            }
            
        }
        return ans;
    }
};