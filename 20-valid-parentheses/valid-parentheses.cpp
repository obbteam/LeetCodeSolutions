#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;

        int count = 0;
        while (s[count] != '\0') {
            if (s[count] == '(' || s[count] == '{' || s[count] == '[') {
                myStack.push(s[count]);
            } else {
                if (myStack.empty() || // if the stack is empty or
                    s[count] == ')' && myStack.top() != '(' ||
                    s[count] == '}' && myStack.top() != '{' ||
                    s[count] == ']' && myStack.top() != '[') {
                        return false;
                    }
                myStack.pop();
            }
            count++;
        }
        return myStack.empty();
    }
};