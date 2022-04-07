class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int TOP1 = pq.top();
            pq.pop();
            int TOP2 = pq.top();
            pq.pop();
            if(TOP1>TOP2)
                pq.push(TOP1-TOP2);
            else
                pq.push(TOP2-TOP1);
            }
        if(pq.size()==0)return 0;
        else return pq.top();
        }
    };