class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int prefix = 0;
        int suffix = 0; 
        int sum = 0;
        for(int i = 0; i < n;i++){
            sum = sum + nums[i];
        }
        for(int i=0;i<n;i++){
            if(i>0){
                prefix = prefix + nums[i-1];
            }
            suffix = sum - nums[i] - prefix;

            if(prefix == suffix){
                return i;
            }
        }
        return -1;
    }
};