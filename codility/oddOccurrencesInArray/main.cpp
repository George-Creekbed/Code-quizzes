#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A) {
    unordered_map<int, int> hash_table;

    for (unsigned ii = 0; ii != A.size(); ++ii) {
        int key = A[ii];
        hash_table[key] += 1;
    }

    for (auto iter = hash_table.begin(); iter != hash_table.end(); ++iter){
        if (iter->second % 2 == 1)
            return iter->first;
    }

    return -1;
}

int main()
{
    vector<int> input = {9,3,9,3,9,7,9};
    int sol = solution(input);
    cout << "{9,3,9,3,9,7,9} ? 7: " << sol << endl;

    return 0;
}
