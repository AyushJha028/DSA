class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[] (const vector<int>& a ,const vector<int>& b){
            return a[1] < b[1];
        });
        int ans=1;
        int n=points.size();
        int temp=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0] > temp){
                temp = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};