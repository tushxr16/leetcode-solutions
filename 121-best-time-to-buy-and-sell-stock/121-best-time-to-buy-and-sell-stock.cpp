class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, n = prices.size();
        vector<int> mn(n,INT_MAX);
        for(int i=1;i<n;i++){
            mn[i] = mn[i-1]<prices[i-1]? mn[i-1] : prices[i-1] ;
        }
        for(int i=0;i<n;i++){
            if(prices[i]>mn[i])
                maxP = maxP>prices[i]-mn[i]? maxP: prices[i]-mn[i];
        }
        return maxP;
    }
};