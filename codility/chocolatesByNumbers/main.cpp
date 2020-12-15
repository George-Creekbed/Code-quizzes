#include <iostream>
#include <vector>

using namespace std;

int solution(int N, int M) {
    if (N == 1)
        return 1;

    int counter(0);
    if (N >= M)
        ++counter;
    int current_pos(0);
    while (counter < 2 || current_pos != 0) {
        counter += (N - 1 - current_pos) / M;
        if ( (N - current_pos) % M == 0 )
            return counter;
        current_pos = M - (N - current_pos) % M;
        counter++;
    }

    return counter;
}

int main()
{
    vector<int> input = {10,4};
    int sol = solution(input[0], input[1]);
    cout << "{10,4} ? 5: " << sol << endl;

    return 0;
}
