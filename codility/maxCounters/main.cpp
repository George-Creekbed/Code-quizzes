#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> &A) {
    vector<int> sol;
    int current_max = 0;
    int last_increase = 0;

    for(int i=0; i<N;i++){
        sol.push_back(0);
    }

    for(unsigned int i=0; i<A.size();i++){
        if (A[i] > N) {
            last_increase = current_max;
        } else {
            sol[A[i]-1] = max(sol[A[i]-1], last_increase);
            sol[A[i]-1]++;
            current_max = max(current_max, sol[A[i]-1]);
        }
    }

    for(int i=0; i<N;i++){
        sol[i] = max(sol[i], last_increase);
    }

    return sol;
}

int main()
{
    vector<int> input = {3,4,4,6,1,4,4};
    vector<int> sol = solution(5, input);
    cout << "{5, [1,3,1,4,2,3,5,4]} ? {3,2,2,4,2}: { ";
    for (auto i : sol)
        cout << i << " ";
    cout << "}" << endl;

    return 0;
}
