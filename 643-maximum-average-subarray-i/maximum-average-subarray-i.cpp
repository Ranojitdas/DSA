class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = k;
        double avg;
        double output;
        double sum;
        double initsum = 0;
        for(int i = 0 ; i < k ; i++){
            initsum = initsum + nums[i];
        }
        sum = initsum;
        output=sum/k;

        while(right < n){
            sum = ((sum + nums[right]) - nums[left]);
            avg = sum/k;
            if(avg > output){
                output = avg;
            }
            left++;
            right++;
        }
    return output;
    }
};