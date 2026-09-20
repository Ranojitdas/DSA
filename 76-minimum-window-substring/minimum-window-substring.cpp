bool correct(vector<int> &s, vector<int> &t){
    for(int i = 0; i < 256; i++){
        if(s[i] < t[i]){
            return false;
        }
    }
    return true;
}
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int low = 0;
        int high = 0;
        int res = INT_MAX;
        int start = 0;
       vector<int> have(256,0);
        vector<int> needed(256,0);
        for(int i=0;i < m; i++){
            needed[t[i]]++;
        }

        for(high = 0; high < n; high++){
            have[s[high]]++;

            while(correct(have,needed)){
                int len = high - low + 1;
                if(res > len){
                    res = len;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
        }
        if(start == 0 and res == INT_MAX){
            return "";
        }
        else{
            return s.substr(start,res);
        }
        
    }
};