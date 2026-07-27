class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),[] (const vector<int>& a ,const vector<int>& b){
            return a[0] < b[0];
        });
        int n=intervals.size();
        vector<vector<int>> ans;
        vector<int> prev=intervals[0];
        for(int i=1;i<n;i++){
            vector<int> interval=intervals[i];
            if(interval[0] <= prev[1]){
                prev[1] = max(interval[1],prev[1]);
            }
            else{
                ans.push_back(prev);
                prev=interval;
            }
        }
        ans.push_back(prev);
        return ans;
    }
};