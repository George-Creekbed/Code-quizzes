#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string isValid(string s) {
    int s_size = s.size();
    if (s_size == 1)
        return "YES";

    map<char,int> counter;
    for (int ii = 0; ii != s_size; ++ii)
        counter[s[ii]]++;

    pair<const char, int> maximum_pair = 
        *max_element( 
            counter.begin(), 
            counter.end(),
            [&](pair<const char, int> a, pair<const char, int> b) {
                return a.second < b.second;
            } 
        );
    int maximum = maximum_pair.second;

    int elements_at_one_less_maximum(0), elements_at_maximum(0);
    bool erased = false;
    for (auto iter = counter.begin(); iter != counter.end(); ++iter) {
        if (iter->second < maximum - 1 && erased)
            return "NO";
        else if (iter->second < maximum - 1 && !erased)
            erased = true;

        if (iter->second == maximum - 1)
            elements_at_one_less_maximum++;
        else if (iter->second == maximum)
            elements_at_maximum++;
        if ( ((elements_at_maximum > 1 && !erased) ||
              (elements_at_maximum > 0 && erased))
              &&
             ((elements_at_one_less_maximum > 1 && !erased) ||
              (elements_at_one_less_maximum > 0 && erased)) )
            return "NO";
    }

    return "YES";
}


int main()
{
    string input = "abc";
    string sol = isValid(input);
    cout << "abc ? YES: " << sol << endl;

    input = "abcc";
    sol = isValid(input);
    cout << "abcc ? YES: " << sol << endl;

    input = "abccc";
    sol = isValid(input);
    cout << "abccc ? NO: " << sol << endl;

    input = "aabbcd";
    sol = isValid(input);
    cout << "aabbcd ? NO: " << sol << endl;

    input = "aabbccddeefghi";
    sol = isValid(input);
    cout << "aabbccddeefghi ? NO: " << sol << endl;

    input = "abcdefghhgfedecba";
    sol = isValid(input);
    cout << "abcdefghhgfedecba ? YES: " << sol << endl;

    input = "aaaabaa";
    sol = isValid(input);
    cout << "aaaabaa ? YES: " << sol << endl;

    input = "aaaaaaa";
    sol = isValid(input);
    cout << "aaaaaaa ? YES: " << sol << endl;

    input = "aabbc";
    sol = isValid(input);
    cout << "aabbc ? YES: " << sol << endl;

    input = "xxxaabbccrry";
    sol = isValid(input);
    cout << "xxxaabbccrry ? NO: " << sol << endl;
    return 0;
}
