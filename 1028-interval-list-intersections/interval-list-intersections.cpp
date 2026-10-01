class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int n = firstList.size();
        int m = secondList.size();
        int i = 0;
        int j = 0;

        while(i<n and j<m){
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];

            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            if(start1<= start2){
                if(end1 >= start2){
                    res.push_back({(max(start1,start2)),(min(end1,end2))});
                }
            }else{
                if(end2 >= start1){
                    res.push_back({(max(start1,start2)),(min(end1,end2))});
                }
            }
            if(end1 <= end2){
                i++;
            }else{
                j++;
            }
        }
        return res;
    }
};