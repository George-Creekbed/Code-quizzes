/* Does not achieve maximum score */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class MyQueue {
    public:
    void enqueue(int input) {
        tail.emplace(input);
        restack_en();
    }
    
    int dequeue() {
        int ret;
        if (!head.empty()) {
            ret = head.top();
            head.pop();
            //restack_de();
        } else {
            ret = tail.top();
            tail.pop();
        }
        
        return ret;
    }
    
    int top() {
        if (!head.empty()) 
            return head.top();
        else
            return tail.top();
    }
    
    private:
    stack<int> head, tail;
    void restack_en() {
        stack<int> aux_h, aux_t;
        size_t diff = tail.size() - head.size();
        if (diff > 1) {
            while (!head.empty()) {
                aux_h.emplace(head.top());
                head.pop();
            }
            while (!tail.empty()) {
                aux_t.emplace(tail.top());
                tail.pop();
            }
            while (diff > 1) {
                aux_h.emplace(aux_t.top());
                aux_t.pop();
                diff -= 2;
            }
            while (!aux_t.empty()) {
                tail.emplace(aux_t.top());
                aux_t.pop();
            }
            while (!aux_h.empty()) {
                head.emplace(aux_h.top());
                aux_h.pop();
            }
        }
    }
    
    void restack_de() {
        stack<int> aux_h, aux_t;
        size_t diff = head.size() - tail.size();
        if (diff > 1) {
            while (!head.empty()) {
                aux_h.emplace(head.top());
                head.pop();
            }
            while (!tail.empty()) {
                aux_t.emplace(tail.top());
                tail.pop();
            }
            while (diff > 1) {
                aux_t.emplace(aux_h.top());
                aux_h.pop();
                diff -= 2;
            }
            while (!aux_t.empty()) {
                tail.emplace(aux_t.top());
                aux_t.pop();
            }
            while (!aux_h.empty()) {
                head.emplace(aux_h.top());
                aux_h.pop();
            }
        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
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
        else if (type == 3)
            cout << my_q.top() << '\n';
    }
    
    return 0;
}
