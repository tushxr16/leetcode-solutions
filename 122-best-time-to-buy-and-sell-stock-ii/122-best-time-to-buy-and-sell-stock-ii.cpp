class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, n = prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                maxP += (prices[i]-prices[i-1]);
            }
        }
        return maxP;
    }
};