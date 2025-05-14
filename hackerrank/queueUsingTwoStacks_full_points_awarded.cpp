#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;


class MyQueue {
public:
    stack<int> stack_newest_on_top, stack_oldest_on_top;
    
    void enqueue(int x) {
       stack_newest_on_top.push(x);
    }

    void dequeue() {
        if (stack_oldest_on_top.empty()) {
            while (!stack_newest_on_top.empty()) {
                stack_oldest_on_top.push(stack_newest_on_top.top());
                stack_newest_on_top.pop();
            }
        }
        stack_oldest_on_top.pop();
    }

    int top() {
        if (stack_oldest_on_top.empty()) {
            while (!stack_newest_on_top.empty()) {
                stack_oldest_on_top.push(stack_newest_on_top.top());
                stack_newest_on_top.pop();
            }
        }
        return stack_oldest_on_top.top();
    }
};

int main() {
    int Q, type, x;
    MyQueue my_q;
    cin >> Q;
    for (int i = 0; i != Q; ++i) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            my_q.enqueue(x);
        } else if (type == 2)
            my_q.dequeue();
        else
            cout << my_q.top() << '\n';
    }
    
    return 0;
}
