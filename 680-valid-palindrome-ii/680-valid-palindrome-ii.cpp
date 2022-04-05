class Solution {
public:
    bool validPalindrome(string s) {
        int low=0,high=s.size()-1;
        return isPalin(s,low,high,0);
    }
    
    bool isPalin(string s,int low,int high,int cnt){
        if(cnt>1)return false;
        while(low<high){
            if(s[low]==s[high]){
                low++;high--;
            }else{
                return isPalin(s,low+1,high,cnt+1) || isPalin(s,low,high-1,cnt+1);
            }
        }
        return true;
    }
};