#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> &A) {
    unordered_set<int> storage;
    for (size_t i = 0; i != A.size(); ++i) {
        if (A[i] >= 0)
            storage.insert(A[i]);
        else
            storage.insert( abs(A[i]) );
    }

    return storage.size();
}

int main()
{
    vector<int> input = {-5,-3,-1,0,3,6};
    int sol = solution(input);
    cout << "{-5,-3,-1,0,3,6} ? 5: " << sol << endl;

    return 0;
}
