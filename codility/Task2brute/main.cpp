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
    while ( ii < S.size() ) {                        // traverse the input
        if (S[ii - 1] == S[ii]) {                    // 2 adjacent identical letters found
            int minimum = min(C[ii - 1], C[ii]);
            ret += minimum;                          // add the one with smaller cost to output

            // in case the smaller was the second one, the first needs to be kept...
            // ...in case this is a block of more than 2 adj. ident. letters
            if (minimum == C[ii]) {
                size_t jj = ii + 1;   // a second index jj traverses the block of adj. ident. letters
                bool flag_loop = false;
                int local_max = C[ii - 1];

                // Nested loop, adds the cost of each letter in the block except for the highest one
                while (jj != S.size() && S[ii] == S[jj]) {
                    ret += min(local_max, C[jj]);
                    if (C[jj] > local_max)
                        local_max = C[jj];
                    jj++;
                    flag_loop = true;
                }

                // in case a block of more than 2 adj. ident. letters was just processed,
                // adjust the main loop index ii accordingly
                if (flag_loop)
                    ii = jj;
            }
        }
        ii++;
    }

    return ret;
}


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

    input0 = "aa";
    input1 = {1,1};
    sol = solution(input0, input1);
    cout << "aa, [1,1]? 1: " << sol << endl;

    input0 = "aa";
    input1 = {1,2};
    sol = solution(input0, input1);
    cout << "aa, [1,2]? 1: " << sol << endl;

    input0 = "ab";
    input1 = {1,1};
    sol = solution(input0, input1);
    cout << "ab, [1,1]? 0: " << sol << endl;

    input0 = "aaa";
    input1 = {1,1,2};
    sol = solution(input0, input1);
    cout << "aaa, [1,1,2]? 2: " << sol << endl;

    input0 = "aab";
    input1 = {1,1,4};
    sol = solution(input0, input1);
    cout << "aab, [1,1,4]? 1: " << sol << endl;

    input0 = "baa";
    input1 = {1,1,4};
    sol = solution(input0, input1);
    cout << "baa, [1,1,4]? 1: " << sol << endl;

    input0 = "abcdefg";
    input1 = {1,1,4,3,5,6,2};
    sol = solution(input0, input1);
    cout << "abcdefg, [1,1,4,3,5,6,2]? 0: " << sol << endl;

    return 0;
}

