class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        int n=st.size();
        int i=0;
        //sort(st.begin(),st.end());
        for(int s:st){
            nums[i++] = s;
        }
        return n; 
    }
};