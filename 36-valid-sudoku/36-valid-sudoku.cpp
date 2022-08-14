class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(st.find("row"+to_string(i)+board[i][j])!=st.end() || 
                       st.find("col"+to_string(j)+board[i][j])!=st.end() ||
                       st.find("box"+to_string(3*(i/3) + j/3)+board[i][j])!=st.end()
                      )
                        return false;
                    st.insert("row"+to_string(i)+board[i][j]);
                    st.insert("col"+to_string(j)+board[i][j]);
                    st.insert("box"+to_string(3*(i/3)+j/3)+board[i][j]);
                }
            }
        }
        return true;
    }
};