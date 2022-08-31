class Solution {
public:
    int maxProfit(vector<int>& price) {
        int maxP = 0, n = price.size();
        vector<int> minPrice(n,INT_MAX);
        for(int i=1;i<n;i++){
            minPrice[i]=minPrice[i-1]>price[i-1]?price[i-1]:minPrice[i-1];
        }
        for(int i=0;i<n;i++){
            if(minPrice[i]<price[i])
            maxP = maxP>price[i]-minPrice[i]?maxP:price[i]-minPrice[i];
        }
        return maxP;
    }
};