class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        int res = 0;
        int freq = 0;
        for(high = 0; high < n;high++){
            if(nums[high] == 1){
                freq++;
            }
            int len = high - low + 1;
            int diff = len - freq;
            while(diff > k){
                if(nums[low] == 1){
                     freq--;
                }
                low++;
                len = high - low + 1;
                diff = len - freq;
            }
            len = high - low + 1;
            res = max(len,res);
        }
        return res;
    }
};