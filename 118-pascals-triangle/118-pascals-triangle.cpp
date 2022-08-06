class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v;
        v.push_back({1});
        if(n==1)
            return v;
        v.push_back({1,1});
        for(int i=2;i<n;i++){
            vector<int> tmp(i+1,1);
            for(int j=0;j<(i+1)/2;j++){
                tmp[j+1] = v[i-1][j]+v[i-1][j+1];
                tmp[i-j-1] = tmp[j+1];
            }
            v.push_back(tmp);
        }
        return v;
    }
};