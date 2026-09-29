class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0;
        int ones=0;
        int twos=0;
        int n=nums.size();
        for(auto it:nums){
            if(it == 0){
                zero++;
            }
            else if(it == 1){
                ones++;
            }
            else{
                twos++;
            }
        }
        int i=0;
        while(zero){
            nums[i++] = 0;
            zero--;
        }
        while(ones){
            nums[i++] = 1;
            ones--;
        }
        while(twos){
            nums[i++] = 2;
            twos--;
        }

    }
};