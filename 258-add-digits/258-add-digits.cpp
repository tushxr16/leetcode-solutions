class Solution {
public:
    int addDigits(int &num) {
        if(num<10){
            return num;
        }else{
            int nextNum = 0;
            while(num){
                nextNum += num%10;
                num /= 10;
            }
            return addDigits(nextNum);
        }
    }
};