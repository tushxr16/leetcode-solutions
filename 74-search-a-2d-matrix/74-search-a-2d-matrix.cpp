class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        for(int i=0;i<m;i++){
            if(matrix[i][n-1]>=target){
                int low=0,high=n-1;
                while(low<=high){
                    int mid = (low+high)/2;
                    if(matrix[i][mid]==target)return true;
                    else if(matrix[i][mid]>target)high--;
                    else low++;
                }
                return false;
            }
        }
        return false;
    }
};