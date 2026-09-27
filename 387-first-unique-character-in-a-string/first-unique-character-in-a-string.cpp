class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char,int> f;
        char prev = s[0];
        for(int i =0; i < n; i++){
            f[s[i]]++;
        }
        for(int i=0; i<n;i++){
            int freq = f[s[i]];
            if(freq == 1){
                return i;
            }
        }
        return -1;
    }
};