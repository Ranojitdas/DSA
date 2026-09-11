class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = n-1;
    int k  = n-1;
    vector<int> res(n);
    while(j>=i){
        if(abs(nums[j])>=abs(nums[i])){
            res[k]=nums[j]*nums[j];
            j--;
            k--;
        }
        else {
            res[k]=nums[i]*nums[i];
            i++;
            k--;
        }
    }
    return res;
    }
};