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
        columnNumber = columnTitle.size();
        for(int i=0;i<columnNumber/2;i++)
            swap(columnTitle[i],columnTitle[columnNumber-i-1]);
        return columnTitle;
    }
};