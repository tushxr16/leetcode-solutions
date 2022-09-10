class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size(), carry = 0, copyK = k;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            int sum = carry + num[i] + copyK%10;
            ans.push_back(sum%10);
            carry = sum/10;
            copyK = copyK/10;
        }
        copyK += carry;
        while(copyK){
            ans.push_back(copyK%10);
            copyK /= 10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};