class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();

        int low = 0;
        int left =0;
        int output = 0;

        while(left < n){
            if(s[low] == t[left]){
                low++;
                left++;
                output++;
            }
            else{
                left++;
            }
        }
        if(output == m){
            return true;
        } else {return false;}
    }
};