class Solution {
public:
    string convertToTitle(int columnNumber) {
        string columnTitle;
        columnNumber--;
        while(columnNumber>=0){
            columnTitle += (columnNumber%26 + 'A');
            columnNumber /= 26;
            columnNumber--;
        }
        
        reverse(columnTitle.begin(),columnTitle.end());
        
        return columnTitle;
    }
};