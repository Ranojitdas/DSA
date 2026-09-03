class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();

        for(int i=0;i<n-2;i++){
            if(i>0 and nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1;
                int right = n-1;
                while(right > left){
                int sum = nums[left] + nums[right];
                if(sum == -(nums[i])){
                    result.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    while(left < n and nums[left] == nums[left - 1]){ 
                        left++;
                    }
                    right--;
                    while(right > 0  and nums[right] == nums[right + 1]){
                        right--;
                    }
                }
                else if(sum > -(nums[i])){
                    right--;
                }
                else if(sum < -(nums[i])){
                    left++;
                }
            }
        }
        return result;
    }
};