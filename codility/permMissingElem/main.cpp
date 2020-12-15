#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    if ( A.empty() )
        return 1;

    std::sort( A.begin(), A.end() );
    vector<int> aux(A.size(), 0);
    for (std::vector<int>::size_type i = 1; i != A.size() + 1; ++i) {
        aux[i-1] = i;
        if (aux[i-1] != A[i-1])
            return i;
    }

    return A.size() + 1;
}

int main()
{
    vector<int> input = {2,3,1,5};
    int sol = solution(input);
    cout << "{2,3,1,5} ? 4: " << sol << endl;

    return 0;
}
