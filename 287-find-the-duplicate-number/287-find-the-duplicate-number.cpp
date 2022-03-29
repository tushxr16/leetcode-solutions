class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bitset<100001> b;
        for(auto x:nums){
            if(b[x]!=0)return x;
            else b[x]=1;
        }
        return -1;
    }
};