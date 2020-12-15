#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    if (A.empty() || A.size() == 1)
        return 0;

    int minimum = A[0];
    int max_profit = 0;
    for (vector<int>::size_type ii = 0; ii != A.size(); ++ii) {
        if (A[ii] < minimum )
            minimum = A[ii];
        max_profit = std::max(max_profit, A[ii] - minimum);
    }

    return max_profit;
}

int main()
{
    vector<int> input = {23171,21011,21123,21366,21013,21367};
    int sol = solution(input);
    cout << "{23171,21011,21123,21366,21013,21367} ? 356: " << sol << endl;

    return 0;
}
