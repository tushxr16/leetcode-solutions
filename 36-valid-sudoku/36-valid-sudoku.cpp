class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<int> st;
            for(int j=0;j<9;j++){
                if(st.find(board[i][j])!=st.end() && board[i][j]!='.'){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        for(int i=0;i<9;i++){
            unordered_set<int> st;
            for(int j=0;j<9;j++){
                if(board[j][i]!='.' && st.find(board[j][i])!=st.end()){
                    return false;
                }
                st.insert(board[j][i]);
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                unordered_set<int> st;
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if(board[i+k][j+l]!='.' && st.find(board[i+k][j+l])!=st.end()){
                            return false;
                        }
                        st.insert(board[i+k][j+l]);
                    }
                }
            }
        }
        return true;
    }
};