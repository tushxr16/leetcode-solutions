class LRUCache {
public:
    int cap;
    list<pair<int,int>> paging;
    unordered_map<int,list<pair<int,int>>::iterator> cache;
    LRUCache(int capacity) {
        cap = capacity;
        return;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            int val = cache[key]->second;
            paging.erase(cache[key]);
            paging.push_back({key,val});
            cache[key] = --paging.end();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.size()<cap || cache.find(key)!=cache.end()){
            if(cache.find(key)!=cache.end()){
                paging.erase(cache[key]);
            }
            paging.push_back({key,value});
            cache[key] = --paging.end();
        }else{
            cache.erase(paging.front().first);
            paging.pop_front();
            return put(key,value);
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */