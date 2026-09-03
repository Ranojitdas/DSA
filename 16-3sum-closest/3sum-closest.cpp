class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int result = nums[0] + nums[1] + nums[2];
        sort(nums.begin(),nums.end());
        int sum3;
        for(int i = 0 ; i < n-2 ; i++){
            int left= i+1;
            int right=n-1;
            
            while(right>left){
                int sum = nums[left] + nums[right]+nums[i];
                if(sum == target){
                    result = target;
                    break;
                }
                else if(abs(sum-target)<abs(result-target)){
                    result = sum;
                }
                else if(sum  > target){
                    right--;
                }
                else left++;
            }
        }
        return result;
    }
};