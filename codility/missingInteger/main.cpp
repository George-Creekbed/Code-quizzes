#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    int max = *std::max_element(A.begin(), A.end());
    if (max < 0)
        max = 0;
    vector<int> counters(max, 0);
    for (auto iter = A.begin(); iter != A.end(); ++iter) {
        if (*iter > 0)
            counters[*iter - 1]++;
    }
    for (int ii = 0; ii != max; ++ii) {
        if (counters[ii] == 0)
            return ii + 1;
    }

    return (max == 0 ? 1 : max + 1);
}

int main()
{
    vector<int> input = {1,3,6,4,1,2};
    int sol = solution(input);
    cout << "{1,3,6,4,1,2} ? 5: " << sol << endl;

    return 0;
}
