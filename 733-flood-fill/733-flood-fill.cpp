class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int R = image.size(), C = image[0].size();
        int onColor = image[sr][sc];
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                pair<int,int> p = q.front();
                q.pop();
                if(image[p.first][p.second]==onColor && image[p.first][p.second]!=color){
                    image[p.first][p.second] = color;
                    if(p.first+1<R){
                        q.push({p.first+1,p.second});
                    }
                    if(p.first-1>=0){
                        q.push({p.first-1,p.second});
                    }
                    if(p.second+1<C){
                        q.push({p.first,p.second+1});
                    }
                    if(p.second-1>=0){
                        q.push({p.first,p.second-1});
                    }
                }
            }
        }
        return image;
    }
};