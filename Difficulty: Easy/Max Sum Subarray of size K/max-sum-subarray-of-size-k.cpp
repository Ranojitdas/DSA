class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = k;
        double sum = 0;
        for(int i = 0; i < k ; i++ ){
            sum = sum + arr[i];
        }
        double res = sum;
        while(high < n){
            sum = ((sum + arr [high])- arr[low]);
            low++;
            high++;
            res = max(sum,res);
        }
        return res;
    }
};