class Solution {
public:
    static int solve(int n){
        int sum=0;
        while(n > 0){
            int d = n% 10;
            n=n/10;
            sum += d;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted(nums);

        auto lambda =[](int num1,int num2){
            int  num1sum = solve(num1);
            int num2sum = solve(num2);
            if(num1sum != num2sum){
                return num1sum < num2sum;
            }

            return num1 < num2;
        };
        sort(sorted.begin(),sorted.end(), lambda);

        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]] = i;
        }

        int swapCount = 0;
        for(int i=0;i<n;i++){
            int exval =  sorted[i];
            int curr = nums[i];

            if(exval == curr)
                continue;
            
            int idx = mpp[exval];
            nums[i] = exval;
            nums[idx] = curr;

            mpp[exval] = i;
            mpp[curr] = idx;

            swapCount++;
        }
        return swapCount;
    }
};