class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int best = nums[0];
        int ans = nums[0];
        int worst = nums[0];

        for(int i=1; i<n; i++){
            int b1 = best * nums[i];
            int b2 = worst * nums[i];
            int b3 = nums[i];

            if(b1 >= b2 and b1 > b3){
                best = b1;
            }else if(b2 > b1 and b2 > b3){
                best = b2;
            }else{
                best = b3;
            }

            if(b1 <= b2 and b1 < b3){
                worst = b1;
            }else if(b2 < b1 and b2 < b3){
                worst = b2;
            }else{
                worst = b3;
            }

            ans=max(ans,best);
        }
        return ans;
    }
};