#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// optimal solution
int solution(vector<int> &A) {
    if (A.size() == 3)
        return 0;

    int A_size = A.size();
    vector<int> max_sum_l(A_size, 0);
    vector<int> max_sum_r(A_size, 0);
    vector<int> max_slice(A_size, 0);

    for (int jj = 1; jj != A_size-1; ++jj)
        max_sum_l[jj] = std::max(0, max_sum_l[jj-1] + A[jj]);

    for (int jj = A_size-2; jj != 0; --jj)
        max_sum_r[jj] = std::max(0, max_sum_r[jj+1] + A[jj]);

    for (int ii = 1; ii != A_size - 1; ++ii)
        max_slice[ii] = max_sum_l[ii-1] + max_sum_r[ii+1];

    return *std::max_element( max_slice.begin(), max_slice.end() );
}

// non-optimal solution: achieves 69% score on codility
int nonOptimalSolution(vector<int> &A) {
    if (A.size() == 3)
        return 0;

    int max_sum(0), minimal(10001), max_slice(0);
    for (vector<int>::size_type ii = 1; ii != A.size() - 1; ++ii) {
        max_sum = std::max(0, max_sum + A[ii]);
        if (max_sum != 0)
            minimal = std::min(minimal, A[ii]);
        if (abs(max_sum) > abs(minimal))
            max_slice = std::max(max_slice, max_sum - minimal);
        else if (max_sum > 0)
            max_slice = std::max(max_slice, max_sum);
    }

    return max_slice;
}

int main()
{
    vector<int> input = {3,2,6,-1,4,5,-1,2};
    int sol = solution(input);
    //int sol = nonOptimalSolution(input);
    cout << "{3,2,6,-1,4,5,-1,2} ? 17: " << sol << endl;

    return 0;
}
