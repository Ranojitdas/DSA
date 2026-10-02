class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(st.top() == '(' and s[i] == ')'){
                st.pop();
                continue;
            }
            if(st.top() == '{' and s[i] == '}'){
                st.pop();
                continue;
            }
            if(st.top() == '[' and s[i] == ']'){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};