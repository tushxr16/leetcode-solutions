class Solution {
public:
    bool isPowerOfTwo(int n) {
        int temp = n, one = 0;
        while(temp){
            one += (temp%2);
            temp /=2;
        }
        return one==1 && n>=0;
    }
};