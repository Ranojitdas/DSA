class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = i+1;
        while(j<n){
            if(nums[i]==0 and nums[j]==0){
                j++;
            }
            else if(nums[i] == 0){
                int k = nums[i];
                nums[i] = nums[j];
                nums[j] = k;
                i++;
                j++;
            }
            else {
                i++;
                j++;
            }
        }

    }
};