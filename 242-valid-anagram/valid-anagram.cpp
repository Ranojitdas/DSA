class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char,int> g;
        for(int i=0;i<n;i++){
            g[s[i]]++;
        }
        for(int i=0;i<m;i++){
            int freq = g[t[i]];
            if(freq == 0){
                return false;
                break;
            } else{
                g[t[i]]--;
                if(g[t[i]] == 0){
                    g.erase(t[i]);
                }
            }
        }
        if(g.size() == 0){
            return true;
        } else return false;
    }
};