typedef pair<int,int> ppi;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto &num:nums){
            mpp[num]++;
        }
        priority_queue<ppi,vector<ppi>,greater<ppi>> maxHeap;
        for(auto i : mpp){
            maxHeap.push({i.second,-i.first});
        }
        vector<int> ans;
        while(! maxHeap.empty()){
            int count=maxHeap.top().first;
            int val=-(maxHeap.top().second);
            maxHeap.pop();
            for(int i=0;i<count;i++){
                ans.push_back(val);
            }
        }
        return ans;
    }
};