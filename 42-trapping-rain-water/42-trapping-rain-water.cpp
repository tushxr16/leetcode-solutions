class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> tmp;int lmax=0;
        for(int i=0;i<height.size();i++){tmp.push_back(lmax);lmax=max(lmax,height[i]);}lmax=0;
        for(int i=0;i<height.size();i++){lmax=max(lmax,height[height.size()-1-                           i]);tmp[height.size()-1-i]=min(tmp[height.size()-1-i],lmax);}lmax=0;
        for(int i=0;i<height.size();i++){if(tmp[i]-height[i]>0)lmax+=(tmp[i]-height[i]);}
        return lmax;
    }
};