#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string &S) {
    if ( S.empty() )
        return 1;

    stack<char> chars;
    for (auto i : S) {
        if (i == ')' && !( chars.empty() ) && chars.top() == '(')
            chars.pop();
        else if (i == '(' || i == ')')
            chars.push(i);
    }

    if ( chars.empty() )
        return 1;

    return 0;
}

int main()
{
    string input = "(()(())())";
    int sol = solution(input);
    cout << "(()(())()) ? 1: " << sol << endl;

    input = "())";
    sol = solution(input);
    cout << "()) ? 0: " << sol << endl;

    return 0;
}
