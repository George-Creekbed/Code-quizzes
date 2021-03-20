//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;

//int solution(vector<int> &A) { // missingInteger
//    int max_A = max(*max_element(A.begin(), A.end()), 0);
//    if (max_A == 0)
//        return 1;
//    vector<int> counter(max_A, 0);
//    for (auto ii : A){
//        if (ii > 0)
//            counter[ii]++;
//    }
//
//    unsigned ret(0);
//    for (unsigned jj = 1; jj != counter.size(); ++jj) {
//        if (counter[jj] == 0){
//            ret = jj;
//            break;
//        }
//    }
//
//    if (ret == 0)
//        ret = max_A + 1;
//
//    return ret;
//}

//#include <string>
//
//using std::string;
//
//string solution(int N) {
//    // code below is not really needed, just makes sol less boring
//    int alphabet_size = 26;
//    string alphabet = "abcdefghijklmnopqrstuvwyxz";
//    if (N <= alphabet_size)
//        return alphabet.substr(0, N);
//    // end of unneeded part
//
//    if (N % 2 == 0) {
//        string a(N-1, 'a');
//        return string(a + "b");
//    }
//
//    return string(N, 'a');
//}

// Tests
//200
//199
//14
//25
//26
//27
//28

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;      using std::vector;
using std::min;
using std::cout;        using std::endl;

int solution(string &S, vector<int> &C) {
    int N = S.size();
    if (N == 1)
        return 0;

    int ret(0);
    size_t ii = 1;
    while ( ii < S.size() ) {
        if (S[ii - 1] == S[ii]) {
            int minimum = min(C[ii - 1], C[ii]);
            ret += minimum;
//            if (ii < S.size())
//                cout << "S[ii-1]: [" << S[ii-1] << "," << C[ii-1]
//                     << "] vs S[ii]: [" << S[ii] << "," << C[ii]
//                     << "] gives current ret: " << ret << endl;
            if (minimum == C[ii]) {
                size_t jj = ii + 1;
                bool flag_loop = false;
//////////////////////////////////////////////////////////////////////////////////////
                int local_max = C[ii - 1];                  // NEW SINCE CODILITY TEST
                // Nested loop, worsens time complexity
                while (jj != S.size() && S[ii] == S[jj]) {
                    ret += min(local_max, C[jj]);           // MODIFIED
                    if (C[jj] > local_max)                  // NEW
                        local_max = C[jj];                  // NEW
//////////////////////////////////////////////////////////////////////////////////////
//                    if (jj < S.size())
//                        cout << "S[ii-1]: [" << S[ii-1] << "," << local_min
//                             << "] vs S[jj]: [" << S[jj] << "," << C[jj]
//                             << "] gives current ret: " << ret << endl;
                    jj++;
                    flag_loop = true;
                }
                if (flag_loop)
                    ii = jj;
            }
        }
        ii++;
    }

    return ret;
}

// tests
//(abbbcddbbb, [1,3,2,2,1,2,4,3,2,1])
//('aaaaaa', [1,1,1,1,1,1])
//('aaaaaa', [1,0,1,0,1,0])
//('aaaaaa', [0,0,1,0,0,0])
int main()
{
    string input0 = "abbbcddbbb";
    vector<int> input1 = {1,3,2,2,1,2,4,3,2,1};
    int sol = solution(input0, input1);
    cout << "abbbcddbbb, [1,3,2,2,1,2,4,3,2,1] ? 9: " << sol << endl;

    input0 = "aaaaaa";
    input1 = {1,1,1,1,1,1};
    sol = solution(input0, input1);
    cout << "aaaaaa, [1,1,1,1,1,1]? 5: " << sol << endl;

    input0 = "aaaaaa";
    input1 = {1,0,1,0,1,0};
    sol = solution(input0, input1);
    cout << "aaaaaa, [1,0,1,0,1,0]? 2: " << sol << endl;

    input0 = "aaaaaa";
    input1 = {0,0,1,0,0,0};
    sol = solution(input0, input1);
    cout << "aaaaaa, [0,0,1,0,0,0]? 0: " << sol << endl;

    input0 = "aaaaaa";
    input1 = {0,0,1,2,4,0};
    sol = solution(input0, input1);
    cout << "aaaaaa, [0,0,1,2,4,0]? 3: " << sol << endl;

    input0 = "aaaaaa";
    input1 = {0,1,2,3,4,5};
    sol = solution(input0, input1);
    cout << "aaaaaa, [0,1,2,3,4,5]? 10: " << sol << endl;

    input0 = "aaaaaabba";
    input1 = {5,4,3,2,1,0,2,2,1};
    sol = solution(input0, input1);
    cout << "aaaaaabba, [5,4,3,2,1,0,3,2,1]? 12: " << sol << endl;

    input0 = "aaaaaabba";
    input1 = {1,2,3,4,5,0,3,4,4};
    sol = solution(input0, input1);
    cout << "aaaaaabba, [1,2,3,4,5,0,2,3,4]? 13: " << sol << endl;

    return 0;
}
