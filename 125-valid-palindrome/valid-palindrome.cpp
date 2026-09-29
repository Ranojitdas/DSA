class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int high =n-1;
        int low =0;
        while(high>low){
            while(low < high and !isalnum(s[low])){
                low++;
            }
            while(low < high and !isalnum(s[high])){
                high--;
            }
            if(tolower(s[low])!=tolower(s[high])){
                return false;
                break;
            }
            low++;
            high--;
        }
        return true;
    }
};