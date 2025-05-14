#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s{""}; 
    stack<string> s_stack;
    s_stack.push(s);
    string Q{};
    getline(cin, Q);
    int q = stoi(Q);
    
    for (int i=0; i!=q; ++i) {
        string command;
        getline(cin, command);
        string text;
        int k;
        switch(command[0]) {
            case '1':
                text = command.substr(2);
                s.append(text);
                s_stack.push(s);
                break;
            case '2':
                k = stoi(command.substr(2));
                s.erase(s.size()-k);
                s_stack.push(s);
                break;
            case '3':
                k = stoi(command.substr(2));
                cout << s[k-1] << endl;
                break;
            case '4':
                if (!s_stack.empty()) {
                    s_stack.pop();
                    s = s_stack.top();
                } 
                break;
        }
    }
    
    return 0;
}
