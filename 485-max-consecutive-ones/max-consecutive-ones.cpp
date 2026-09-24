class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        int output = 0;

        for(high = 0; high < n; high++){
            while(nums[high] == 0 and low <= high){
                low++;
            }
            output = max(output , high-low+1);
        }
        return output;
    }
};