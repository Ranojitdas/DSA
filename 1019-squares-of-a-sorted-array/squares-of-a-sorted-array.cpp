class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<= (nums.size() - 1);i++){
            nums[i] = nums[i] * nums[i];
        }

        for(int i=0;i<=(nums.size()-1);i++){
        for(int j=i+1;j<= (nums.size()-1);j++){
            if(nums[i] > nums[j]){
               int k = nums[i];
               nums[i] = nums[j];
               nums[j] = k;
        }
        }
        }
        return nums;
    }
};