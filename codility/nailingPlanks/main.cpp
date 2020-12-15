#include <iostream>
#include <vector>

using namespace std;

bool AllNailed(int planksCount, vector<int> &A, vector<int> &B, vector<int> &C)
{
    vector<int> nailsMarked(2 * C.size() + 1, 0);
    for (int i = 0; i < planksCount; i++)
        nailsMarked[C[i]] = 1;

    for (size_t i = 1; i < nailsMarked.size(); i++)
        nailsMarked[i] += nailsMarked[i - 1];

    bool allNailed = true;
    for (size_t i = 0; i < A.size() && allNailed; i++)
        allNailed = nailsMarked[B[i]] - nailsMarked[A[i] - 1] > 0;

    return allNailed;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int minPlanks = 1;
    int maxPlanks = C.size();
    int result = -1;
    while (minPlanks <= maxPlanks) {
        int midPlanks = (maxPlanks + minPlanks) / 2;
        if ( AllNailed(midPlanks, A, B, C) ) {
            maxPlanks = midPlanks - 1;
            result = midPlanks;
        }
        else
            minPlanks = midPlanks + 1;
    }

    return result;
}

int main()
{
    vector<int> input0 = {1,4,5,8};
    vector<int> input1 = {4,5,9,10};
    vector<int> input2 = {4,6,7,10,2};
    int sol = solution(input0, input1, input2);
    cout << "{[1,4,5,8], [4,5,9,10], [4,6,7,10,2]} ? 4: " << sol << endl;

    return 0;
}
