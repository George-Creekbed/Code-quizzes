#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    if ( A.empty() )
        return 0;
    else if (A.size() == 1)
        return 1;

    int min_value = *std::min_element( A.begin(), A.end() );
    int max_value = *std::max_element( A.begin(), A.end() );
    max_value = std::max( abs(min_value), abs(max_value) );
    vector<int> counters(max_value + 1, 0);
    vector<int> counters_neg(max_value + 1, 0);
    for (auto i : A) {
        if (i < 0)
            counters_neg[abs(i)] += 1;
        else
            counters[i] += 1;
    }
    auto aux = std::remove(counters.begin(), counters.end(), 0);
    counters.erase( aux, counters.end() );
    auto aux_neg = std::remove(counters_neg.begin(), counters_neg.end(), 0);
    counters_neg.erase( aux_neg, counters_neg.end() );

    return counters.size() + counters_neg.size();
}

int main()
{
    vector<int> input = {2,1,1,2,3,1};
    int sol = solution(input);
    cout << "{2,1,1,2,3,1} ? 3: " << sol << endl;

    return 0;
}
