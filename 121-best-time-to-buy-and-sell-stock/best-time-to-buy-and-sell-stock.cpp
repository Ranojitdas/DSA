class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int best = prices[0];
        int worst = prices[0];
        int res = 0;

        for(int i=1;i<n;i++){
            if(prices[i]>best){
                best = prices[i];
            }
            if(prices[i]<worst){
                worst = prices[i];
                best = prices[i];
            }
            int len = best - worst;
            res = max(res,len);
        }
        return res;
    }
};

// solved in first try myself using kadane :)