#include <iostream>
#include <cmath>

using namespace std;

int solution(int N) {
    int counter = 0;
    int i = 1;
    double root = sqrt(N);
    while (i < root) {
        if (N % i == 0) counter += 2;
        ++i;
    }
    if (i == root)
        ++counter;

    return counter;
}

int main()
{
    int input = 24;
    int sol = solution(input);
    cout << "24 ? 8: " << sol << endl;

    return 0;
}
