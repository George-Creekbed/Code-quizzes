#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

vector<int> fibonacciUntilN(int N)
{
    vector<int> output;
    output.reserve(N);
    output.push_back(0);
    output.push_back(1);
    int fib_number = output[0] + output[1];
    output.push_back(fib_number);
    for (int i = 3; fib_number <= N; ++i) {
        fib_number = output[i-1] + output[i-2];
        if (fib_number <= N)
            output.push_back(fib_number);
    }
    output = vector<int>(output.begin()+2, output.end() );

    return output;
}

// non-optimal solution: achieves 75% score on codility
int solution(vector<int> &A)
{
    int N = A.size();
    if (A.empty())
        return 1;
    else if (N < 3)
        return 1;

    vector<int> fib_numbers = fibonacciUntilN(N);
    int fib_size = fib_numbers.size();
    vector< vector<int> > dp_fib_jumps;
    for (int i = 0; i != fib_size; ++i) {
        int current_fib = fib_numbers[i];
        if (A[current_fib-1] == 1) {
            vector<int> current_path;
            current_path.push_back(current_fib);
            if (current_fib == N + 1)
                return current_path.size();
            dp_fib_jumps.push_back(current_path);
        }
    }

    for (vector< vector<int> >::size_type i = 0; i != dp_fib_jumps.size(); ++i) {
        int accum = accumulate(dp_fib_jumps[i].begin(), dp_fib_jumps[i].end(), 0);
        for (int j = 0; j != fib_size; ++j) {
            if (accum <= N + 1 && A[accum-1] == 1) {
                int temp = accum + fib_numbers[j];
                vector<int> current_path(dp_fib_jumps[i]);
                if (temp <= N + 1 && (temp == N + 1 || A[temp-1] == 1)) {
                    current_path.push_back(fib_numbers[j]);
                    dp_fib_jumps.push_back(current_path);
                }
                if (temp == N + 1)
                    return current_path.size();
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> input = {0,0,0,1,1,0,1,0,0,0,0};
    int sol = solution(input);
    cout << "{0,0,0,1,1,0,1,0,0,0,0} ? 3: " << sol << endl;

    return 0;
}
