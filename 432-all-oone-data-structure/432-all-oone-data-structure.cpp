class AllOne {
public:
    unordered_map<string,int> freq;
    set<pair<int,string>> st;
    AllOne() {
        
    }
    
    void inc(string key) {
        if(freq.find(key)!=freq.end()){
            st.erase({freq[key],key});
            freq[key]++;
            st.insert({freq[key],key});
        }else{
            freq[key]++;
            st.insert({freq[key],key});
        }        
        return;
    }
    
    void dec(string key) {
        if(freq.find(key)!=freq.end()){
            st.erase({freq[key],key});
            freq[key]--;
            if(freq[key]==0){
                freq.erase(key);
            }else{
                st.insert({freq[key],key});
            }
            return;
        }
    }
    
    string getMaxKey() {
        if(st.size()!=0){
            auto itr = *(st.rbegin());
            return itr.second;
        }else{
            return "";
        }
    }
    
    string getMinKey() {
        if(st.size()!=0){
            auto itr = *(st.begin());
            return itr.second;
        }else{
            return "";
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */