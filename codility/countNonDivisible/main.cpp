#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> &A) {
    int N = A.size();
    vector<int> counts (*std::max_element(A.begin(), A.end()) + 1,0);

    // Calculate occurrences of each number in the array
    for (int i = 0; i < N; ++i)
        counts[A[i]] += 1;

    // Assume each number has 0 non dividers
    std::vector<int> answer(N,0);

    // For each element of the array
    for (int i = 0; i < N; ++i) {
        // Calculate how many of its divisors are in the array
        int divisors = 0;
        for (int j = 1; j * j <= A[i]; ++j) {
            if (A[i] % j == 0) {
                divisors += counts[j];
                if (A[i] / j != j)
                    divisors += counts[A[i] / j];
            }
        }

        // Subtract the number of divisors from the number of elements in the array
        answer[i] = N - divisors;
    }

    return answer;
}

int main()
{
    vector<int> input = {3,1,2,3,6};
    vector<int> sol = solution(input);
    cout << "{3,1,2,3,6} ? {2,4,3,2,0}: { ";
    for (auto i : sol)
        cout << i << " ";
    cout << "}" << endl;

    return 0;
}
