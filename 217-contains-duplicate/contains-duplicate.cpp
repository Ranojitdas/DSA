class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> f;

        for(int i=0;i<n;i++){
            if(f.contains(nums[i])){
                return true;
            }else{
                f[nums[i]]++;
            }
        }
        return false;
    }
};