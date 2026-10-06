class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> f;
        vector<int> ans;

        for(int i=0;i<n;i++){
            int comp = target - nums[i];
            if(f.contains(comp)){
                ans.push_back(i);
                ans.push_back(f[comp]);
            }else{
                f[nums[i]] = i;
            }
        
        }
        return ans;
    //     int n = nums.size();
    //     int low = 0;
    //     int high = low + 1;
    //     int sum = 0;
    //     vector<int> ans;
    //     for(int i = 0;i<n;i++){
    //         for(int j=i+1; j<n;j++){
    //             int sum = nums[i] + nums[j];
    //             if(sum == target){
    //                 ans.push_back(i);
    //                 ans.push_back(j);
    //                 break;
    //             }
    //         }
    //     }
    //     return ans;
    // }
    }
};