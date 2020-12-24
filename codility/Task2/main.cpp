#include <iostream>
#include <vector>
#include <string>
#include <queue>

using std::string;      using std::vector;
using std::priority_queue;
using std::cout;        using std::endl;

int solution(string &S, vector<int> &C) {
    int N = S.size();
    if (N == 1)
        return 0;

    int ret(0);
    priority_queue<int> repeated_adjacent;  // heap data structure (max value at root node)
    size_t ii = 1;
    while ( ii < S.size() ) {                   // traverse input string
        if (S[ii - 1] == S[ii]) {               // found adjacent identical letters
            repeated_adjacent.push(C[ii - 1]);  // keep adding adjacent identical letters to the heap until..

            // ..either (a) letter is last input or (b) next letter is not identical
            if (ii == S.size()-1 || ( ii < S.size()-1 && S[ii] != S[ii+1]) ) {
                repeated_adjacent.push(C[ii]);      // add last identical letter
                repeated_adjacent.pop();            // take letter with highest cost C out of the heap

                // add costs of the other identical letters to output and empty the heap (linear with the heap size)
                while ( !(repeated_adjacent.empty()) ) {
                    ret += repeated_adjacent.top();
                    repeated_adjacent.pop();
                }
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
    cout << "aaaaaabba, [5,4,3,2,1,0,2,2,1]? 12: " << sol << endl;

    input0 = "aaaaaabba";
    input1 = {1,2,3,4,5,0,3,4,4};
    sol = solution(input0, input1);
    cout << "aaaaaabba, [1,2,3,4,5,0,3,4,4]? 13: " << sol << endl;

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
