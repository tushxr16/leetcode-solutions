class Solution {
public:
    vector<string> result;
    
    struct Trie{
        Trie *child[26];
        bool isWord;
        
        Trie(){
            isWord = false;
            for(int i=0;i<26;i++){
                child[i] = NULL;
            }
        }
    };
    
    Trie *root = new Trie();
    
    void addWord(string &word){
        Trie *node = root;
        for(char c: word){
            if(!node->child[c-'a']){
                node->child[c-'a'] = new Trie();
            }
            node = node->child[c-'a'];
        }
        node->isWord = true;
    }
    void dfs(int i, int j, Trie *node, string word, vector<vector<char>> &board){
        int n = board.size(), m = board[0].size();
        if(i<0 || j<0 ||
           i>=n || j>=m ||
           board[i][j]=='-')
            return;
        node = node->child[board[i][j]-'a'];
        if(node==nullptr){
            return;
        }
        
        word += board[i][j];
        
        if(node->isWord){
            result.push_back(word);
            node->isWord = false;
        }
        
        char temp = board[i][j];
        board[i][j] = '-';
        
        dfs(i+1,j,node,word,board);
        dfs(i-1,j,node,word,board);
        dfs(i,j+1,node,word,board);
        dfs(i,j-1,node,word,board);
        
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        int n = board.size(), m = board[0].size();
        
        for(auto word: words){
            addWord(word);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(i,j,root,"",board);
            }
        }
        return result;
    }
};