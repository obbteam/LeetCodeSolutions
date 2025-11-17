class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string w;
        for (char c : s) {
            if (c == ' ') {
                if (!w.empty()) {
                    st.push(w);
                    w.erase();
                }
                continue;
            }
            w += c;
        }
        if(!w.empty())
            st.push(w);

        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (st.size() > 0)
                ans += ' ';
        }

        return ans;
    }
    
};