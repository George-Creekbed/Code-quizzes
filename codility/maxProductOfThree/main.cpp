#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    std::sort( A.begin(), A.end() );
    int prod_pos = *(A.rbegin() + 1) * *(A.rbegin() + 2);
    int prod_neg = *(A.begin()) * *(A.begin() + 1);
    if (prod_pos > prod_neg || *(A.rbegin()) < 0)
        return *(A.rbegin()) * prod_pos;
    else
        return *(A.rbegin()) * prod_neg;

    return 0;
}

int main()
{
    vector<int> input = {-3,1,2,-2,5,6};
    int sol = solution(input);
    cout << "{-3,1,2,-2,5,6} ? 60: " << sol << endl;

    return 0;
}
