class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size() - 1;
        int i = 0;
        int j = 1;

            while(j<=n){
                if (nums[i] != nums[j]){
                    nums[i+1] = nums[j];
                    i++;
                }
                else j++;
        }
        return i+1 ;
    }
};