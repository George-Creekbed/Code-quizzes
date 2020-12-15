#include <iostream>
#include <vector>

using namespace std;

// non-optimal solution: achieves 53% score on codility
int solution(vector<int> &A) {
    if (A.size() < 3)
        return 0;
    if (A.size() == 3) {
        if (A[0] < A[1] && A[2] < A[1])
            return 1;
        else
            return 0;
    }

    vector<int> peaks;
    for (vector<int>::size_type i = 1; i != A.size() - 1; ++i) {
        if ( A[i] > A[i-1] && A[i] > A[i+1])
            peaks.push_back(i);
    }
    if ( peaks.empty() )
        return 0;
    else if (peaks.size() == 1)
        return 1;

    vector<int>::size_type peaks_size = peaks.size();
    int curr_distance = (peaks[peaks_size-1] - peaks[0])/2 + 1;
    int counter(1);
    while (curr_distance > 0) {
        for (vector<int>::size_type i = 0; peaks[i]+curr_distance <= peaks[peaks_size-1]; ++i) {
            int old_i = i;
            for (vector<int>::size_type j = i + 1; j < peaks_size; ++j) {
                if (peaks[j] - peaks[i] >= curr_distance) {
                    ++counter;
                    i = j;
                }
            }
            if (counter >= curr_distance)
                return curr_distance;
            counter = 1;
            i = old_i;
        }
        curr_distance--;
    }

    return 0;
}

int main()
{
    vector<int> input = {1,5,3,4,3,4,1,2,3,4,6,2};
    int sol = solution(input);
    cout << "{1,5,3,4,3,4,1,2,3,4,6,2} ? 3: " << sol << endl;

    return 0;
}
