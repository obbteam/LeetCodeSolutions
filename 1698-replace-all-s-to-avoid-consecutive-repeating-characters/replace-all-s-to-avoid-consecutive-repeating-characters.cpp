class Solution {
public:
    string modifyString(string s) {
        std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

        if(s[0]=='?') {
            int k = doSmth('.',s[1]);
            s[0] = alphabet[k];
        }

        if(s[s.length()-1]=='?') {
            int k = doSmth(s[s.length()-2],'.');
            s[s.length()-1] = alphabet[k];
        }

        for(int i = 1; i < s.length() - 1; i++)
         {
            if(s[i] == '?') {
                auto prev = s[i-1];
                auto next = s[i+1];
                int k = doSmth(prev,next);
                s[i] = alphabet[k];
            }
         }
         return s;
    }

    int doSmth(char prev, char next) {
        std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

        int k = 0;
                while(alphabet[k] == prev || alphabet[k] == next) {
                    k++;
                }
                return k;
    }
};