class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        int q = queries.size();
        auto lambda = [](vector<int>& a , vector<int>& b){
            return a[1] < b[1];
        };
        sort(logs.begin(),logs.end(),lambda);

        vector<int> result(q);
        vector<pair<int,int>> timeInd(q);
        unordered_map<int,int> mpp;

        for(int i=0;i<q;i++){
            timeInd[i] = {queries[i],i};
        }

        sort(timeInd.begin(),timeInd.end());

        int i = 0;
        int j = 0;
        for(auto [time,idx] : timeInd){
            int start = time - x;
            int end = time;

            while(j<m && logs[j][1] <= end ){
                mpp[logs[j][0]]++;
                j++;
            }

            while(i<m && logs[i][1] < start){
                mpp[logs[i][0]]--;
                if(mpp[logs[i][0]] == 0 ){
                    mpp.erase(logs[i][0]);
                }
                i++;
            }

            result[idx] = n - mpp.size();

        }
        return result;
    }
};