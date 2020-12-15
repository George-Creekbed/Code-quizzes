#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int solution(string &S) {
    if ( S.empty() )
        return 1;

    stack<char> mystack;
    if (S.front() == '{' || S.front() == '[' || S.front() == '(')
        mystack.push( S.front() );
    else
        return 0;

    bool is_opening = true;
    int bracket_type = 3;
    for (auto ii = ++S.begin(); ii != S.end(); ++ii) {
        if (mystack.top() == '{' || mystack.top() == '[' || mystack.top() == '(') {
            is_opening = true;
            if (mystack.top() == '{')
                bracket_type = 0;
            else if (mystack.top() == '[')
                bracket_type = 1;
            else if (mystack.top() == '(')
                bracket_type = 2;
        } else
            is_opening = false;

        mystack.push(*ii);

        if (mystack.size() > 1) {
            if (is_opening) {
                if ( (bracket_type == 0 && mystack.top() == '}') || (bracket_type == 1 && mystack.top() == ']') || (bracket_type == 2 && mystack.top() == ')') ) {
                    mystack.pop();
                    mystack.pop();
                }
            } else if (!is_opening)
                return 0;
        }
    }

    if ( mystack.empty() )
        return 1;

    return 0;
}

int main()
{
    string input = "{[()()]}";
    int sol = solution(input);
    cout << "{[()()]} ? 1: " << sol << endl;

    input = "([)()]";
    sol = solution(input);
    cout << "([)()] ? 0: " << sol << endl;

    return 0;
}
