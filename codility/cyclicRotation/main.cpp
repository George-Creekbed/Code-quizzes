#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
    if ( !A.empty() ) {
        for (int ii = 0; ii != K; ++ii) {
            for (unsigned jj = 0; jj != A.size() - 1; ++jj)
                std::swap(A[jj], A[A.size() - 1]);
        }
    }

    return A;
}


int main()
{
    vector<int> input = {3,8,9,7,6};
    vector<int> sol = solution(input, 3);
    cout << "{[3,8,9,7,6], 3} ? {9,7,6,3,8}: {";
    for (auto i : sol)
        cout << i << " ";
    cout << "}" << endl;

    input = {0,0,0};
    sol = solution(input, 3);
    cout << "{[0,0,0], 1} ? {0,0,0}: { ";
    for (auto i : sol)
        cout << i << " ";
    cout << "}" << endl;

    input = {1,2,3,4};
    sol = solution(input, 4);
    cout << "{[1,2,3,4], 4} ? {1,2,3,4}: { ";
    for (auto i : sol)
        cout << i << " ";
    cout << "}" << endl;

    return 0;
}
