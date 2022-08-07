class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, temp = 0, n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(temp!=0)
                    ans = temp;
                temp = 0;
            }else{
                temp++;
            }
            if(temp!=0)
                    ans = temp;
        }
        return ans;
    }
};