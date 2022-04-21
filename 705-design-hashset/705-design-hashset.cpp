class MyHashSet {
public:
    map<int,int> mp;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(mp.find(key)==mp.end())mp[key]=1;
        else mp[key]++;
        return;
    }
    
    void remove(int key) {
        if(mp.find(key)!=mp.end())mp.erase(key);
        return;
    }
    
    bool contains(int key) {
        if(mp.find(key)==mp.end())return false;
        else return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */