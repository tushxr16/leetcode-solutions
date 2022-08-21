class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> ans(n,0);
        int idx = 0;
        for(int i=0;i<n;i++)
            ans[i] = i+1;
        while(ans.size()!=1){
            idx = (idx+k-1)%n;
            ans.erase(ans.begin()+idx,ans.begin()+idx+1);
            n--;
        }
        return ans[0];
    }
};