class Solution {
public:    
    bool isWord(int i, int j, int k, string &word, vector<vector<char>> &board){
        int n = board.size(), m = board[0].size();
        if(k==word.size()){
            return true;
        }
        if(i<0 || j<0 || 
           i>=n || j>=m || 
           word[k] != board[i][j])
            return false;
        char temp = board[i][j];
        board[i][j] = '-';
        bool res = isWord(i+1,j,k+1,word,board) || 
                   isWord(i-1,j,k+1,word,board) || 
                   isWord(i,j+1,k+1,word,board) ||
                   isWord(i,j-1,k+1,word,board);
        board[i][j] = temp;
        return res;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWord(i,j,0,word,board))
                    return true;
            }
        }
        return false;
    }
};