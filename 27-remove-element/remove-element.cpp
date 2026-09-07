class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int output=0;

        while(right >= left){ 

            if(nums[left] == val and nums[right] != val){
                swap(nums[left],nums[right]);
                output++;
                left++;
            }
            else if(left < n and nums[left] != val){
                output++;
                left++;
            }
            else if(nums[right] == val){
                right--;
            }
        }
        return output;
    }
};