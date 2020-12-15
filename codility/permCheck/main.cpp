#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    if (A.size() == 1) {
        if (A[0] == 1)
            return 1;
        else
            return 0;
    }

    int N = A.size();
    int max_el = *max_element( A.begin(), A.end() );
    if (max_el != N)
        return 0;

    vector<int> counters(max_el, 0);
    for (auto i : A) {
        counters[i-1]++;
    }

    for (int j = 0; j != max_el; ++j) {
        if (counters[j] == 0)
            return 0;
    }

    return 1;
}

int main()
{
    vector<int> input = {4,1,3,2};
    int sol = solution(input);
    cout << "{4,1,3,2} ? 1: " << sol << endl;

    input = {4,1,3};
    sol = solution(input);
    cout << "{4,1,3} ? 0: " << sol << endl;

    return 0;
}
