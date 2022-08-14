class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int temp = 0, n = s.size();
        for(int i=0;i<n-1;i++){
            if(mp[s[i]]<mp[s[i+1]]){
                temp -= mp[s[i]];
            }else{
                temp += mp[s[i]];
            }
        }
        temp += mp[s[n-1]];
        return temp;
    }
};