class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int best = nums[0];
        int worst = nums[0];
        int absbest = abs(nums[0]);
        int ans = absbest;

        for(int i = 1; i < n; i++){
            int b1 = best + nums[i];
            int b2 = worst + nums[i];
            int b3 = nums[i];

            best = max({b1,b2,b3});
            worst = min({b1,b2,b3});
            absbest=max({abs(b1),abs(b2),abs(b3)});
            ans = max(ans,absbest);
        }
        return ans;
    }
};