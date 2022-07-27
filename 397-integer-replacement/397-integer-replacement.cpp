class Solution {
public:
    int integerReplacement(int n) {
        if(n==INT_MAX){
            return log2(INT_MAX)+2;
        }
        if(n==1){
            return 0;
        }
        if(n&1){
            return 1 + min(integerReplacement(n-1),integerReplacement(n+1));
        }else{
            return 1 + integerReplacement(n/2);
        }
    }
};