#include <iostream>
#include <string>

using std::cout;             using std::endl;
using std::string;

string solution(int N) {
    // code below is not really needed, just makes sol less boring
    int alphabet_size = 26;
    string alphabet = "abcdefghijklmnopqrstuvwyxz";
    if (N <= alphabet_size)
        return alphabet.substr(0, N);
    // end of unneeded part

    if (N % 2 == 0) {
        string a(N-1, 'a');
        return string(a + "b");
    }

    return string(N, 'a');
}

int main()
{
    int input = 200;
    string sol = solution(input);
    cout << "200 ? last b: " << sol << endl;

    input = 199;
    sol = solution(input);
    cout << "199 ? all a : " << sol << endl;

    input = 14;
    sol = solution(input);
    cout << "14 ? alpahabet until n: " << sol << endl;

    input = 25;
    sol = solution(input);
    cout << "25 ? alphabet minus z: " << sol << endl;

    input = 26;
    sol = solution(input);
    cout << "26 ? whole alphabet: " << sol << endl;

    input = 27;
    sol = solution(input);
    cout << "27 ? all a : " << sol << endl;

    input = 28;
    sol = solution(input);
    cout << "28 ? last b: " << sol << endl;

    return 0;
}
// Tests
//200
//199
//14
//25
//26
//27
//28
