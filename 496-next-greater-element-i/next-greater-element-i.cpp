class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int> st;
        vector<int> res(m);
        vector<int> output(n);

        res[m-1] = -1;
        st.push(nums2[m-1]);

        for(int j=m-2;j>=0;j--){
            while(!st.empty() and st.top() <= nums2[j]){
                st.pop();
            }
            if(st.empty()){
                res[j] = -1;
            }else{
                res[j] = st.top();
            }
            st.push(nums2[j]);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i] == nums2[j]){
                    output[i] = res[j];
                }
            }
        }
        return output;
    }
};