class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> output;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(j > i+1 and nums[j]==nums[j-1]){
                    continue;
                }
                int left = j+1;
                int right = n-1;
                while(right > left){
                long long sum =  (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
                    if(sum == target){
                        output.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        while(left < n and nums[left] == nums[left-1]){
                            left++;
                        }
                        right --;
                        while(right > 0 and nums[right] == nums[right+1]){
                            right--;
                        }
                    }
                    else if(sum > target){
                        right --;
                    }
                    else if(sum < target){
                        left++;
                    }
                }

            }
        }
        return output;
    }
};