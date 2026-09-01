class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(j>i){
            if(!isalnum(s[i])){
                i++;
            }
            else if(!isalnum(s[j])){
                j--;
            }
            else if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            else{
                i++;
                j--;
            }
            
        }
        return true;
    }
};