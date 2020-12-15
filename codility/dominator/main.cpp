#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> &A) {
    stack<int> mystack;
    int candidate = -1;
    for (auto i : A) {
        if (mystack.size() == 0) {
            mystack.push(i);
            candidate = i;
        } else {
            if (mystack.top() != i)
                mystack.pop();
            else
                mystack.push(i);
        }
    }
    int dominator = candidate;
    int ret = -1;
    if (mystack.size() != 0) {
        vector<int>::size_type counter = 0;
        for (vector<int>::size_type i = 0; i != A.size(); ++i) {
            if (A[i] == dominator) {
                ++counter;
                ret = i;
            }
        }
        if (counter > A.size() / 2)
            return ret;
    }

    return -1;
}

int main()
{
    vector<int> input = {3,4,3,2,3,-1,3,3};
    int sol = solution(input);
    cout << "{3,4,3,2,3,-1,3,3} ? 0,2,4,6 or 7: " << sol << endl;

    return 0;
}
