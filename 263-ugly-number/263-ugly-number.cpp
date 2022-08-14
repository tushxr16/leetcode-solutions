class Solution {
public:
    bool isUgly(int n) {
        long long int div = 1;
        if(n<=0){
            return false;
        }
        while(n%div==0){
            div *= 2;
        }
        div /= 2 ;
        while(n%div==0){
            div *= 3;
        }
        div /= 3;
        while(n%div==0){
            div *= 5;
        }
        div /= 5;
        if(n/div==1){
            return true;
        }else{
            return false;
        }
    }
};