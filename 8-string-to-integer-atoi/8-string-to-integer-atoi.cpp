class Solution {
public:
    int myAtoi(string str) {
        long long int result=0,neg=1,i=str.find_first_not_of(' ');
        if(i==-1)i=0;
        if(str[i]=='-' || str[i]=='+')
            neg=(str[i++]=='-')?-1:1;
        
        while('0'<= str[i] && str[i] <= '9') 
        {
            result=result*10+ (str[i++]-'0');
            if(result*neg >= INT_MAX) return INT_MAX;
            if(result*neg <= INT_MIN) return INT_MIN;                
        }   
        return result*neg;
    }
};