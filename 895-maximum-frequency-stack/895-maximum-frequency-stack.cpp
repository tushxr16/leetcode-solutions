class FreqStack {
    priority_queue<pair<int,pair<int,int>>> q;
    unordered_map<int,int> mp;
    int rand = 0;
public:
    void push(int val) {
        q.emplace(++mp[val], make_pair(++rand, val));    
    }
    
    int pop() {
        pair<int,pair<int,int>> ret = q.top();
        q.pop();
        int x = ret.second.second;
        mp[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */