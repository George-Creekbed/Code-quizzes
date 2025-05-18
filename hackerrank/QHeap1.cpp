// my own solution using an auxiliary stack is too slow for 2 testcases out of 18
// found very ingenious alternative solution by someone else
// using an additional priority queue managing the remove command
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int Q, Q_type, v;
    cin >> Q;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    priority_queue<int, vector<int>, greater<int>> my_heap;
    stack<int> aux_stack;
    for (int i = 0; i != Q; ++i) {
        cin >> Q_type;
        if (Q_type == 3)
            cout << my_heap.top() << '\n';
        else{
            cin >> v;
            if (Q_type == 1)
                my_heap.emplace(v);
            else if (Q_type == 2) {
                while (my_heap.top() != v) {
                    aux_stack.emplace(my_heap.top());
                    my_heap.pop();
                }
                my_heap.pop();
                while (!aux_stack.empty()) {
                    my_heap.emplace(aux_stack.top());
                    aux_stack.pop();
                }
            } else
                cout << "error\n";
        };
        //cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    } 
    return 0;
}

// // 100% working solution (not by me):
//
// priority_queue<int, vector<int>, greater<int> > pq;
// priority_queue<int, vector<int>, greater<int> > pqRemove;

// void add(){
//     int n;
//     cin>>n;
//     pq.push(n);
// }

// void remove()
// {
//     int n;
//     cin>>n;
//     pqRemove.push(n);
    
// }

// void printMin(){
    
//     while(!pqRemove.empty() && pqRemove.top() == pq.top()){
//         pq.pop();
//         pqRemove.pop();
//     }
//     cout<<pq.top()<<endl;
// }
    
// int main() {

//     int q;
//     cin>>q;
//     while(q!=0){
//         int command;
//         cin>>command;
//         if(command == 1)
//             add();
//         else if(command == 2)
//             remove();
//         else if(command == 3)
//             printMin();
        
//         q--;
//     }
//     return 0;
// }
