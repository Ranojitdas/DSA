class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int best = nums[0];
        int ans = nums[0];

        for(int i = 1 ; i < n ; i++){
            int b1 = best + nums[i];
            int b2 = nums[i];
            best = max(b1,b2);
            ans = max(ans,best);
        }
        return ans;
    }
};