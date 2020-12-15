#include <iostream>
#include <vector>

using namespace std;

int solution(int A, int B, int K) {
    int div2 = B / K;
    int div1 = A / K;
    if (A % K > 0)
        return div2 - div1;
    else if (A % K == 0)
        return div2 - div1 + 1;

    return 0;
}

int main()
{
    vector<int> input = {6,11,2};
    int sol = solution(input[0], input[1], input[2]);
    cout << "{6,11,2} ? 3: " << sol << endl;

    return 0;
}
