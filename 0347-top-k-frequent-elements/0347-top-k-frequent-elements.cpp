typedef pair<int,int> ppi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        priority_queue<ppi,vector<ppi>,greater<ppi>> minHeap;
        for(auto& num:nums){
            mpp[num]++;
        }

        for(auto& [num,count]:mpp){
            minHeap.push({count,num});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<int> ans;
        while(! minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};