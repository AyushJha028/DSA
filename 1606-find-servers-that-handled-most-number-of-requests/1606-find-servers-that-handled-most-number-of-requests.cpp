class Solution {
public:
    typedef pair<int,int> P;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = load.size();
        vector<int> count(k,0);
        vector<int> ans;
        set<int> availableServers;
        priority_queue<P,vector<P>,greater<P>> busyServers;
        for(int i=0;i<k;i++){
            availableServers.insert(i);
        }
        for(int i=0;i<n;i++){
            int time = arrival[i];

            while(!busyServers.empty() && busyServers.top().first <= time){
                int server = busyServers.top().second;
                busyServers.pop();
                availableServers.insert(server);
            }
            int target = i%k;
            auto it = availableServers.lower_bound(target);
            if(it == availableServers.end()){
                it = availableServers.begin();
            }
            if(availableServers.empty()){
                continue;
            }

            int targetServer = *it;

            availableServers.erase(it);
            busyServers.push({time + load[i], targetServer});
            count[targetServer]++;
        }

        int maxi = INT_MIN;
        for(int i=0;i<k;i++){
            maxi = max(count[i],maxi);
        }
        for(int i=0;i<k;i++){
            if(count[i] == maxi){
                ans.push_back(i);
            }
        }
        return ans;
    }
};