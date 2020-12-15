#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <numeric>

using namespace std;

// non-optimal solution: achieves score of 72% on codility
int solution(vector<int> &A) {
    vector<int> B(A);
    transform(B.begin(), B.end(), B.begin(), [&](int a)->int{return abs(a);});

    int total_sum = accumulate(B.begin(), B.end(), 0);

    int size = total_sum;
    deque<bool> dp(size, false);
    dp[0] = true;

    for_each(B.begin(), B.end(),
        [&](int num) {
            int ii = total_sum - 1;
            while (ii >= 0) {
                if (dp[ii] && ii + num < total_sum)
                    dp[ii + num] = true;
                --ii;
            }
        }
    );

    int result = total_sum;
    int ii = 0;
    while (ii != total_sum / 2 + 1) {
        if ( ii < size && dp[ii] )
            result = min(result, total_sum - 2 * ii);   //ii is not part of the sum any more, plus it gets subtracted
        ++ii;
    }

    return result;
}

int main()
{
    vector<int> input = {1,5,2,-2};
    int sol = solution(input);
    cout << "{1,5,2,-2} ? 0: " << sol << endl;

    return 0;
}
