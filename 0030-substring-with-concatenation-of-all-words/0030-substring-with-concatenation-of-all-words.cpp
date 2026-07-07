class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.size();
        int m=words.size();
        vector<int> ans;
        if(n==0 || m==0)
            return ans;
        int wordSize=words[0].size();
        
        unordered_map<string,int> mpp;
        for(auto &w:words){
            mpp[w]++;
        }

        for(unsigned int offset=0;offset < wordSize;++offset){
            unsigned int size=0;
            unordered_map<string,unsigned int> seen;

            for(unsigned int i=offset;i+wordSize <= n;i+=wordSize){
                string sub=s.substr(i,wordSize);
                auto itr=mpp.find(sub);
                if(itr==mpp.end()){
                    seen.clear();
                    size=0;
                    continue;
                }

                ++seen[sub];
                ++size;

                while(seen[sub] > itr->second){
                    string first=s.substr(i-(size-1)*wordSize,wordSize);
                    --seen[first];
                    --size;
                }
                
                if(size == m){
                    ans.push_back(i-(size-1) * wordSize);
                }
            }
        }
        return ans;
    }
};