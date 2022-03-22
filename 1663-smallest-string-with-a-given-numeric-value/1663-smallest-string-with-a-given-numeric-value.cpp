class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int> arr(n,1);
        k=k-n;
        int zz = k/25;k=k-(zz*25);
        for(int i=0;i<zz;i++)arr[n-i-1]=26;
        if(n-1-zz>-1)arr[n-1-zz]=k+1;
        string s;
        for(int i=0;i<n;i++)s.push_back('a'+arr[i]-1);
        return s;
    }
};