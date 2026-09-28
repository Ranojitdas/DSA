class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> f;
        int res = 0;

        for(int i=0; i<n; i++){
            f[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(f[nums[i]] > n/2){
                res = nums[i];
                break;
            }
        }
        return res;
    }
};