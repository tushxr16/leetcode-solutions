class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,1);
        for(int i=1;i<rowIndex;i++){
            res[i] = (long long int)res[i-1]*((long long int)rowIndex+1-i)/(long long int)(i);
        }
        return res;
    }
};