class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int count = 1;
        for (auto &c : s) {
            if (st.contains(c)){
                count++;
                st.clear();
            }
            st.insert(c);
        }

        return count;
    }
};