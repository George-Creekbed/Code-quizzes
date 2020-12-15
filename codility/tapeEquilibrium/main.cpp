#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> &A) {
    vector<int> aux(A.size(), 0);
    int total_sum = std::accumulate(A.begin(), A.end(), 0);
    std::partial_sum( A.begin(), A.end(), aux.begin() );
    std::for_each(aux.begin(), aux.end(),
        [&](int& el)->int{
            int left_sum(el);
            int right_sum = total_sum - left_sum;
            el = std::abs(left_sum - right_sum);
            return el;
        }
    );

    return *std::min_element( aux.begin(), --aux.end() );
}

int main()
{
    vector<int> input = {3,1,2,4,3};
    int sol = solution(input);
    cout << "{3,1,2,4,3} ? 1: " << sol << endl;

    return 0;
}
