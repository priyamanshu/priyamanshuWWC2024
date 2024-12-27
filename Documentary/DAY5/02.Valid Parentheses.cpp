#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (const char c : s) {
            if (c == '(')
                stack.push(')');
            else if (c == '{')
                stack.push('}');
            else if (c == '[')
                stack.push(']');
            else if (stack.empty() || pop(stack) != c)
                return false;
        }

        return stack.empty();
    }

private:
    int pop(stack<char>& stack) {
        const int c = stack.top();
        stack.pop();
        return c;
    }
};

int main() {
    Solution solution;
    string input = "()[]{}";
    if (solution.isValid(input)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }

    input = "(]";
    if (solution.isValid(input)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }

    return 0;
}