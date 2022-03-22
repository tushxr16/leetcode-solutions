class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int words=1;int n=sentences.size();
        for(int i=0;i<n;i++){
            int temp=1;
            int nn=sentences[i].size();
            for(int j=0;j<nn;j++)
                if(sentences[i][j]==' ')temp++;
            words=max(words,temp);
        }
        return words;
    }
};