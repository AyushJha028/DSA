class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size() -1;
        while(i < j){
            int mid=(i + j )/2;
            int sum = numbers[i] + numbers[j];
            if(sum  == target){
                return {i+1,j+1};
            }
            else if(sum > target){
               // j = mid;
                j--;
            }
            else{
                //i=mid+1;
                i++;
            }
        }
        return {-1,-1};
    }
};