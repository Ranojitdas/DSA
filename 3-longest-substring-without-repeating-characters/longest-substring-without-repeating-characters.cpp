class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<int,int> f;
       int n = s.size();
       int low = 0;
       int high = 0;
       int res = 0;
       for(high = 0; high < n ; high++){
            f[s[high]]++;
            while(f[s[high]] > 1){
                f[s[low]]--;
                low++;
            }
            int len = high - low + 1;
            res = max(len,res);
       }
       return res;
    }
};