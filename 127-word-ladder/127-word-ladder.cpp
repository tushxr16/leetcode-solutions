class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        bool isPresent = false;
        int depth = 0;
        for(string word: wordList){
            if(word==endWord){
                isPresent = true;
            }
            words.insert(word);
        }
        
        if(!isPresent){
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()){
            depth++;
            int n = q.size();
            for(int i=0;i<n;i++){
                string temp = q.front();
                q.pop();
                int m = temp.size();
                for(int j=0;j<m;j++){
                    string changed = temp;
                    for(char c='a';c<='z';c++){
                        changed[j] = c;
                        if(changed==endWord){
                            return ++depth;
                        }
                        if(changed==temp){
                            continue;
                        }
                        if(words.find(changed)!=words.end()){
                            q.push(changed);
                            words.erase(changed);
                        }
                    }
                }
            }
        }
        return 0;
    }
};