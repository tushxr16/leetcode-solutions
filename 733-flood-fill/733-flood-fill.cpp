class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int onColor = image[sr][sc];
        int r = image.size(), c = image[0].size();
        if(color==onColor){
            return image;
        }
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                pair<int,int> p = q.front();
                q.pop();
                image[p.first][p.second] = color;
                if(p.first>0 && image[p.first-1][p.second]==onColor){
                    q.push({p.first-1,p.second});
                }
                if(p.first<r-1 && image[p.first+1][p.second]==onColor){
                    q.push({p.first+1,p.second});
                }
                if(p.second>0 && image[p.first][p.second-1]==onColor){
                    q.push({p.first,p.second-1});
                }
                if(p.second<c-1 && image[p.first][p.second+1]==onColor){
                    q.push({p.first,p.second+1});
                }
            }
        }
        return image;
    }
};