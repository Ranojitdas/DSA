class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    vector<vector<int>> res;
    vector<vector<int>> output;
    bool insert = false;

    if(n == 0){
        res.push_back({newInterval});
    }

    for(int i=0;i<n;i++){
        if(insert == false and intervals[i][0] > newInterval[0]){
            res.push_back({newInterval});
            insert = true;
        }
        res.push_back({intervals[i]});
    }

    if(insert == false){
        res.push_back({newInterval});
    }
    
    int m = res.size();
    int start1 = res[0][0];
    int end1 = res[0][1];
    for(int i=1;i<m;i++){
        int start2 = res[i][0];
        int end2 = res[i][1];
        if(end1 >= start2){
            start1 = start1;
            end1 = max(end1,end2);
            continue;
        }
        output.push_back({start1,end1});
        start1 = start2;
        end1 = end2;
    }
    output.push_back({start1,end1});
    return output;
    }
};