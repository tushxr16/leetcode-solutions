class Solution {
public:
    bool isPowerOfTwo(int n) {
        int one = __builtin_popcount(abs(n));
        return one==1 && n>=0;
    }
};