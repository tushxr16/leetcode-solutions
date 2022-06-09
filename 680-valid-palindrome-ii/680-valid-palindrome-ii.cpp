class Solution {
public:
    bool isPalin(string s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int k = 0, n = s.size()-1;
        while(k<n){
            if(s[k]!=s[n])
                return isPalin(s,k+1,n) || isPalin(s,k,n-1);
            k++;n--;
        }
        return true;
    }
};