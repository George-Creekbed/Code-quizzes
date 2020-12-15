#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int dominator(vector<int> &A) {
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

    if (mystack.size() != 0) {
        vector<int>::size_type counter = 0;
        for (vector<int>::size_type i = 0; i != A.size(); ++i) {
            if (A[i] == dominator)
                ++counter;
        }
        if (counter > A.size() / 2)
            return dominator;
    }

    return -1;
}

int solution(vector<int> &A) {
    int leader = dominator(A);
    int A_size_right = A.size();
    vector<int> left;
    int counter = 0;
    if (leader != -1) {
        int leader_size = count(A.begin(), A.end(), leader);
        vector<int>::size_type leader_size_left = 0;
        int leader_size_right = leader_size;
        for (vector<int>::size_type ii = 0; ii != A.size(); ++ii) {
            left.push_back(A[ii]);
            --A_size_right;
            if (A[ii] == leader) {
                ++leader_size_left;
                --leader_size_right;
            }
            if (leader_size_left > left.size() / 2) {
                if (leader_size_right > A_size_right / 2)
                    ++counter;
            }
        }
    } else
        return 0;

    return counter;
}

int main()
{
    vector<int> input = {4,3,4,4,4,2};
    int sol = solution(input);
    cout << "{4,3,4,4,4,2} ? 2: " << sol << endl;

    return 0;
}
