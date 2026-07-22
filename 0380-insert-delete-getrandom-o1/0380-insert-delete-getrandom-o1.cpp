class RandomizedSet {
public:
    vector<int>nums;
    unordered_map<int,int> mpp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.find(val) != mpp.end())
            return false;
        
        nums.push_back(val);
        mpp[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mpp.find(val) == mpp.end())
            return false;

        int ind=mpp[val];
        int last=nums.back();

        nums.back() = val;
        nums[ind] = last;

        mpp[last] = ind;
        nums.pop_back();
        
        mpp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n=nums.size();
        int ind= rand()%n;
        return nums[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */