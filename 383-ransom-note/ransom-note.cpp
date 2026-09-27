class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m = ransomNote.size();
        int n = magazine.size();
        unordered_map<char,int> need;
        unordered_map<char,int> have;
        for(int i=0;i<m;i++){
            need[ransomNote[i]]++;
        }
        for(int i=0;i<n;i++){
            have[magazine[i]]++;
        }

        for(auto i:need){
            int k = i.first;
            int freq = need[k];
            if(freq > have[k]){
                return false;
                break;
            }
        }
        return true;
    }
};