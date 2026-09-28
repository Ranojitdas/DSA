class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char,int> f;
        int res = 0;

        for(int i=0; i<n; i++){
            f[text[i]]++;
        }
        return min({f['b'],f['a'],f['n'],f['l']/2,f['o']/2});
    }
};