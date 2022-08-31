class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0, n = name.size(), m = typed.size();
        while(j<m){
            if(i<n && j<m && name[i]==typed[j]){
                i++;j++;
            }
            else if(i>0 && i<=n && j<m && name[i-1]==typed[j]){
                j++;
            }
            else{
                break;
            }
        }
        if(j==m && i==n){
            return true;
        }
        return false;
    }
};