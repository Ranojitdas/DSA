class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        if (k <= 1) {
            return 0;
        }

        int low = 0;
        int high = 0;
        int output = 0;
        int product = 1;

        while (high < n) {
            product = product * nums[high];

            while (product >= k) {
                product = product / nums[low];
                low++;
            }

            high++;

            output = output + (high - low);
        }

        return output;
    }
};