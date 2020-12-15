#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// non-optimal solution: achieves 70% score on codility
int solution(int M, vector<int> &A) {
    int N = A.size();
    if (N == 1)
        return 1;

    int* back = &A[0];
    int* front = &A[0];
    int counter(0);
    while (front != &A[0] + N) {
        unordered_set<int> slice;
        slice.insert(*back);
        front++;
        while (slice.count(*front) == 0 && front != &A[0] + N) {
            slice.insert(*front++);
        }
        counter += slice.size();
        ++back;
        front = back;
    }

    return counter;
}

int main()
{
    vector<int> input = {3,4,5,5,2};
    int sol = solution(6, input);
    cout << "{6, [3,4,5,5,2]} ? 9: " << sol << endl;

    return 0;
}
