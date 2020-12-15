#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int X, vector<int> &A) {
    int counter(0), ret(-1);
    vector<int> aux(X, 0);
    for (auto iter = A.begin(); iter != A.end(); ++iter) {
        if (aux[*iter - 1] == 0) {
            aux[*iter - 1] += 1;
            ++counter;
        }
        if (counter == X) {
            ret = (int) ( iter - A.begin() );
            break;
        }
    }

    return ret;
}

int main()
{
    vector<int> input = {1,3,1,4,2,3,5,4};
    int sol = solution(5, input);
    cout << "{5, [1,3,1,4,2,3,5,4]} ? 6: " << sol << endl;

    return 0;
}
