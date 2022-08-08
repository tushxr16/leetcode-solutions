class Solution {
public:
    string convertToTitle(int columnNumber) {
        string columnTitle;
        while(columnNumber){
            int x = columnNumber%26;
            if(x==0)
                x = 26;
            columnTitle.push_back((x-1)+'A');
            columnNumber = (columnNumber-1)/26;
        }
        reverse(columnTitle.begin(),columnTitle.end());
        return columnTitle;
    }
};