#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(vector<int> arr) {
    priority_queue<int> heap( arr.begin(), arr.end() );
    int minimum(INT_MAX);
    while( !(heap.empty()) ) {
        int aux = heap.top();
        heap.pop();
        if (!(heap.empty()) )
            minimum = min(minimum, aux - heap.top());
    }

    return minimum;
}

int main()
{
    vector<int> input = {-2,2,4};
    int sol = minimumAbsoluteDifference(input);
    cout << "{-2,2,4} ? 2: " << sol << endl;

    input = {3,-7,0};
    sol = minimumAbsoluteDifference(input);
    cout << "{3,-7,0} ? 3: " << sol << endl;

    input = {-59,-36,-13,1,-53,-92,-2,-96,-54,75};
    sol = minimumAbsoluteDifference(input);
    cout << "{-59,-36,-13,1,-53,-92,-2,-96,-54,75} ? 1: " << sol << endl;

    input = {1,-3,71,68,17};
    sol = minimumAbsoluteDifference(input);
    cout << "{1,-3,71,68,17} ? 3: " << sol << endl;

    return 0;
}
