class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;
        int res = 0;

        while(true){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            if(slow == fast){
                slow = 0;
                while(slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                res = slow;
                break;
            }
            
        }
        return res;
    }
};