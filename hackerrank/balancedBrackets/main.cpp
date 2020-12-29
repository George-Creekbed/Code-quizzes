#include <iostream>
#include <string>
#include <stack>

using namespace std;

string isBalanced(string s) {
    int s_size = s.size();

    if (s_size == 0)
        return "YES";

    stack<char> brackets;
    for (int ii = 0; ii != s_size; ++ii) {
        if (s[ii] == '{' || s[ii] == '[' || s[ii] == '(')
            brackets.push(s[ii]);
        else if (s[ii] == '}' || s[ii] == ']' || s[ii] == ')') {
            if (brackets.empty())
                return "NO";
            else {
                if ( (brackets.top() == '{' && s[ii] == '}') ||
                     (brackets.top() == '[' && s[ii] == ']') ||
                     (brackets.top() == '(' && s[ii] == ')') )
                    brackets.pop();
                else
                    brackets.push(s[ii]);
            }
        }
    }

    return (brackets.empty() ? "YES" : "NO");
}


int main()
{
    string input = "{[()]}";
    string sol = isBalanced(input);
    cout << "{[()]} ? YES: " << sol << endl;

    input = "{[(])}";
    sol = isBalanced(input);
    cout << "{[(])} ? NO: " << sol << endl;

    input = "{{[[(())]]}}";
    sol = isBalanced(input);
    cout << "{{[[(())]]}} ? YES: " << sol << endl;

    return 0;
}
