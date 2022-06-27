class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            int idx = arr[i]%n;
            arr[idx]+=n;
        }
        for(int i=0;i<n;i++){
            if(arr[i]/n>1)
                return i;
        }
        return -1;
    }
};