#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    vector<int> A(S.size()+1);
    vector<int> C(S.size()+1);
    vector<int> G(S.size()+1);
    vector<int> T(S.size()+1);

    for (size_t i=1;i<=S.size();i++) {
        A[i]=A[i-1]+(S[i-1]=='A'?1:0);
        C[i]=C[i-1]+(S[i-1]=='C'?1:0);
        G[i]=G[i-1]+(S[i-1]=='G'?1:0);
        T[i]=T[i-1]+(S[i-1]=='T'?1:0);
    }

    vector<int> result;
    for (size_t j=0;j < P.size();j++) {
        if (A[Q[j]+1]-A[P[j]]!=0) result.push_back(1);
        else if (C[Q[j]+1]-C[P[j]]!=0) result.push_back(2);
        else if (G[Q[j]+1]-G[P[j]]!=0) result.push_back(3);
        else if (T[Q[j]+1]-T[P[j]]!=0) result.push_back(4);
    }

    return result;
}

int main()
{
    string input0 = "CAGCCTA";
    vector<int> input1 = {2,5,0};
    vector<int> input2 = {4,5,6};
    vector<int> sol = solution(input0, input1, input2);
    cout << "{CAGCCTA, [2,5,0], [4,5,6]} ? {2,4,1}: { ";
    for (auto i : sol)
        cout << i << " ";
    cout << "}" << endl;

    return 0;
}
