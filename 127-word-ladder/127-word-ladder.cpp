class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        bool isPresent = false;
        int n = wordList.size();
        for(int i=0;i<n;i++){
            s.insert(wordList[i]);
            if(wordList[i]==endWord)
                isPresent = true;
        }
        if(!isPresent){
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0, strSize = beginWord.size();
        
        while(!q.empty()){
            depth++;
            n = q.size();
            
            for(int i=0;i<n;i++){
                string curr = q.front();
                q.pop();
                for(int j=0;j<strSize;j++){
                    string temp = curr;
                    for(char c='a';c<='z';c++){
                        temp[j] = c;
                        if(curr==temp){
                            continue;
                        }
                        if(temp==endWord){
                            return depth+1;
                        }
                        if(s.find(temp)!=s.end()){
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};