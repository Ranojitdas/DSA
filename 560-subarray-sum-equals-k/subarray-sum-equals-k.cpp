class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int res = 0;
        unordered_map<int,int> f;
        f[0]=1;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            int prev = sum - k;
            int freq = f[prev];
            res+=freq;
            f[sum]++;
        }
        return res;
    }
};