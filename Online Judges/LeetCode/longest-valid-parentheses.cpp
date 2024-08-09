class Solution {
public:
    int longestValidParentheses(string s) {
        int n;
        int res=0;
        stack<int>st;
        n=s.size();
        s=' '+s;
        st.push(0);
        for (int i=1;i<=n;i++) {
            if (s[i]=='(') st.push(i);
            else {
                if (!st.empty()&&s[st.top()]=='(') {
                    st.pop();
                    res=max(res,i-st.top());
                } else {
                    st.push(i);
                }
            }
        }
        return res;
    }
};
