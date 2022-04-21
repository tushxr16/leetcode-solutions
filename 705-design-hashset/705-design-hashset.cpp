class MyHashSet {
public:
    int v[1000001]={0};
    MyHashSet() {
    }
    
    void add(int key) {
        v[key]++;
        return;
    }
    
    void remove(int key) {
        v[key]=0;
        return;
    }
    
    bool contains(int key) {
        if(v[key]==0)return false;
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