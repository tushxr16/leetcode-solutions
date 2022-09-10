class Solution {
public:
    string addBinary(string a, string b) {
        
        string ans;
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        
        while(i>=0 && j>=0){
            int digit = (a[i]-'0') ^ (b[j]-'0') ^ carry;
            carry = ((a[i]-'0')&(b[j]-'0'))||(carry&((a[i]-'0')^(b[j]-'0')));
            ans.push_back('0'+digit);
            i--;j--;
        }
        
        while(i>=0){
            int digit = (a[i]-'0')^(carry);
            carry = carry&((a[i]-'0'));
            ans.push_back('0'+digit);
            i--;
        }
        while(j>=0){
            int digit = (b[j]-'0')^(carry);
            carry = carry&((b[j]-'0'));
            ans.push_back('0'+digit);
            j--;
        }
        if(carry)
            ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};