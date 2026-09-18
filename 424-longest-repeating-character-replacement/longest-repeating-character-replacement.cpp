int find_max(vector<int> &a){
        int maxc = 1;
        for(int i = 0 ; i < 256; i++){
            maxc = max(maxc,a[i]);
        }
        return maxc;
    }
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0;
        int high = 0;
        int res = 0;
        vector<int> f(256,0);

        for(high = 0;high<n;high++){
            f[s[high]]++;

            int len = high -low+1;
            int max_count = find_max(f);
            int diff = len - max_count;
            while(diff > k){
                f[s[low]]--;
                low++;
             len = high -low+1;
             max_count = find_max(f);
             diff = len - max_count;
            }
            len = high - low + 1;
            res = max(res,len);
        }
        return res;
    }
};