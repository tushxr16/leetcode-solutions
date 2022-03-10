class Solution {
public:
    int reverse(int x) {
        long long int tmp=x;
        long long int rev=0;
        while(tmp){
            rev = rev*10 + tmp%10;
            tmp/=10;
        }
        if(rev<-2147483648 || rev>2147483647)return 0;
        return rev;
    }
};