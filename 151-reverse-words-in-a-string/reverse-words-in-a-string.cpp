class Solution {
public:
    string reverseWords(string s) {
        s = trim(s);

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
    string trim(string& s) {
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            if (s[l] == ' ')
                l++;
            else if (s[r] == ' ')
                r--;
            else
                break;
        }
        return s.substr(l, r - l + 1);
    }
};