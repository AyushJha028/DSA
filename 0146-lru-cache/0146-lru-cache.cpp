class LRUCache {
public:
    list<int> dll;
    map<int, pair<list<int>::iterator,int>> mpp;
    int n;
    LRUCache(int capacity) {
        n= capacity;
    }

    void makeMRU(int key){
        dll.erase(mpp[key].first);
        dll.push_front(key);
        mpp[key].first = dll.begin();
    }
    
    int get(int key) {
        if(!mpp.count(key))
            return -1;

        makeMRU(key);
        return mpp[key].second;
    }
    
    void put(int key, int value) {
        if(mpp.count(key)){
            mpp[key].second = value;
            makeMRU(key);
        }
        else{
            dll.push_front(key);
            mpp[key] = {dll.begin(), value};
            n--;
        }

        if(n < 0){
            mpp.erase(dll.back());
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */