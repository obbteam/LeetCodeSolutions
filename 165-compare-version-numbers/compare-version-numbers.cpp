class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto i1 = 0, i2 = 0;

        while (i1 < version1.length() || i2 < version2.length()) {
            std::string cur1, cur2;

            while (i1 < version1.length() && version1[i1] != '.') {
                cur1 += version1[i1];
                ++i1;
            }

            while (i2 < version2.length() && version2[i2] != '.') {
                cur2 += version2[i2];
                ++i2;
            }

            int toCheck1 = cur1.empty() ? 0 : stoi(cur1);
            int toCheck2 = cur2.empty() ? 0 : stoi(cur2);

            if (toCheck1 < toCheck2)
                return -1;
            if (toCheck1 > toCheck2)
                return 1;

            ++i1;
            ++i2;
        }
        return 0;
    }
};