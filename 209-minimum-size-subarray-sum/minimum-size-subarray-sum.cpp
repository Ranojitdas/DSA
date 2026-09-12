class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        int low = 0;
        int high = 0;
        int sum = 0;
        while(high < n){
            sum = sum + nums[high];
            
            while(sum >= target){
                int len = high - low + 1;
                if(res >= len){
                    res = len;
                }
                sum = sum - nums[low];
                low++;
            }
            high++;
        }
        if(res == INT_MAX){
            return 0;
        }
        else return res;
    }
};