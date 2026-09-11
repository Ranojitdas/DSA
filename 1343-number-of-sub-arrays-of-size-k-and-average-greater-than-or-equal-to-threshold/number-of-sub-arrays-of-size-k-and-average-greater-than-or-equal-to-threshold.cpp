class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int left = 0;
        int right = k;
        double initsum = 0;
        int output = 0;
        double avg;
        for(int i = 0;i<k;i++){
            initsum = initsum + arr[i];
        }
        avg = initsum/k;
        if(avg >= threshold){
            output++;
        }
        double sum = initsum;
        while(right < n){
            sum = ((sum - arr[left])+arr[right]);
            avg = sum/k;
            if(avg >= threshold){
                output++;
                left++;
                right++;
            }
            else{
                left++;
                right++;
            }
        }
        return output;
    }
};