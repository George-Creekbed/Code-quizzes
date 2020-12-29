#include <iostream>
#include <string>

using namespace std;

int alternatingCharacters(string s) {
    int s_size = s.size();

    if (s_size == 1)
        return 0;

    int ret(0);
    for (int ii = 1; ii != s_size; ++ii) {
        if (s[ii-1] == s[ii])
            ret++;
    }

    return ret;
}


int main()
{
    string input = "AAAA";
    int sol = alternatingCharacters(input);
    cout << "AAAA ? 3: " << sol << endl;

    input = "BBBBB";
    sol = alternatingCharacters(input);
    cout << "BBBBB ? 4: " << sol << endl;

    input = "ABABABAB";
    sol = alternatingCharacters(input);
    cout << "ABABABAB ? 0: " << sol << endl;

    input = "BABABA";
    sol = alternatingCharacters(input);
    cout << "BABABA ? 0: " << sol << endl;

    input = "AAABBB";
    sol = alternatingCharacters(input);
    cout << "AAABBB ? 4: " << sol << endl;

    return 0;
}
