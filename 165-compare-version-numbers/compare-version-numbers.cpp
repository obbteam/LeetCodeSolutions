class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto dot1 = version1.find_first_of('.');
        auto dot2 = version2.find_first_of('.');
        int toCompare1 = 0;
        int toCompare2 = 0;
        while (dot1 != string::npos || dot2 != string::npos) {
            toCompare1 = dot1 == string::npos ? stoi(version1)
                                              : stoi(version1.substr(0, dot1));
            toCompare2 = dot2 == string::npos ? stoi(version2)
                                              : stoi(version2.substr(0, dot2));
            if (toCompare1 == toCompare2) {
                version1 = dot1 == string::npos ? version1 = "0"
                                                : version1.substr(dot1 + 1);
                version2 = dot2 == string::npos ? version2 = "0"
                                                : version2.substr(dot2 + 1);
                dot1 = version1.find_first_of('.');
                dot2 = version2.find_first_of('.');
            } else if (toCompare1 > toCompare2)
                return 1;
            else
                return -1;
        }
        toCompare1 = stoi(version1);
        toCompare2 = stoi(version2);
        if (toCompare1 > toCompare2)
            return 1;
        else if (toCompare1 < toCompare2)
            return -1;
        else
            return 0;
    }
};