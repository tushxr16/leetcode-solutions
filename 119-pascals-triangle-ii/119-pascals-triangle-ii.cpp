class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        for(int i=0;i<=rowIndex;i++){
            res.push_back(vector<int>(i+1,1));
            for(int j=1;j<i;j++){
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res[rowIndex];
    }
};