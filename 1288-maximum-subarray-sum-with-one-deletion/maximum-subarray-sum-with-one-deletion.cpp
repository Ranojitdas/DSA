class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int nodelete = arr[0];
        int res = arr[0];
        int onedelete = 0;

        for(int i = 1; i < n ;i++){
            int prevnodelete = nodelete;
            int prevonedelete = onedelete;
            int b1 = nodelete + arr[i];
            int b2 = arr[i];
            nodelete = max(b1,b2);
            int c1 = prevonedelete + arr[i];
            int c2 = prevnodelete;
            if(onedelete == INT_MIN){
                onedelete = prevnodelete;
            } else{
                onedelete = max(c1,c2);
            } 
           
           res = max(res, max(onedelete,nodelete));

        }
        return res;
    }
};