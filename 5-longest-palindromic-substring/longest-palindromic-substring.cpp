class Solution {
public:

    bool isPalindrome(string s) {
        auto start = 0;
        auto end = s.length() - 1;

        while(start <= end) {
            if(s[start] == s[end]){
                ++start;
                end--;
            } else return false;
        }
        return true;
    }


    string longestPalindrome(string s) {
        if(s.length() == 1) return s;
        if(s.length() == 2 && s[0]==s[1]) {
            return s;
        } else if (s.length() == 2 && s[0]!=s[1]) {
            return s.substr(1);
        }


        string result = "";
        
        for(int i = 0; i < s.length(); ++i) {
            auto position = s.find_last_of(s[i]);
            while( position != i ) {
                auto sliced = s.substr(i,position - i + 1);
                if(sliced.length() < result.length()) break;

                if(isPalindrome(sliced)) {
                    result = sliced;
                    break;
                }

                position = s.find_last_of(s[i], position - 1);
            }
        }

        if(result.length() == 0) result.push_back(s[0]);

        return result;
    }
};