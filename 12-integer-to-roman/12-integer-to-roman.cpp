class Solution {
public:
    string intToRoman(int num) {
        int intCode[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string stringCode[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans;
        for(int i=0;i<13;i++){
            while(intCode[i]<=num){
                num -= intCode[i];
                ans += stringCode[i];
            }
        }
        return ans;
    }
};