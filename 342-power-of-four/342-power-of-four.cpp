class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        double temp = (double)log2(n);
        if((ceil(temp)==floor(temp)) && ((int)temp)%2==0)
            return true;
        else
            return false;
    }
};