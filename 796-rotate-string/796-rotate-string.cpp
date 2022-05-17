class Solution {
public:
    bool rotateString(string s, string goal) {
        int s_size=s.size(),goal_size=goal.size();
        if(s_size!=goal_size)return false;
        vector<int> indexes;
        for(int i=0;i<goal_size;i++)
            if(s[0]==goal[i])
                indexes.push_back(i);
        if(indexes.size()==0)return false;
        for(int i=0;i<indexes.size();i++){
            int n=0;
            for(int j=0;j<goal_size;j++){
                if(goal[(j+indexes[i])%goal_size]==s[j])
                    n++;
            }
            if(n==goal_size)return true;
        }
        return false;
    }
};