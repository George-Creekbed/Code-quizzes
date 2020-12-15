#include <iostream>
#include <vector>

using namespace std;

int solution(int X, int Y, int D) {
    if (X == Y)
        return 0;

    int output = (Y - X) / D;
    if (D * output == Y - X)
        return output;

    return output + 1;
}

int main()
{
    vector<int> input = {10,85,30};
    int sol = solution(input[0], input[1], input[2]);
    cout << "{10,85,30} ? 3: " << sol << endl;

    return 0;
}
