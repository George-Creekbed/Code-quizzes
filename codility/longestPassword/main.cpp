#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int solution(string &S)
{
    unsigned i(0), j(1);
    vector<string> words;

    if (S.size() == 1 && S[0] != ' ')
        words.push_back(S);

    while ( j != S.size() ) {
        if (S[j] == ' ') {
            words.push_back( S.substr(i, j-i) );
            i = j + 1;
        } else if (j == S.size() - 1)
            words.push_back( S.substr(i, j-i+1) );
        j++;
    }

    vector<int> passwords_lengths;
    for (auto word : words) {
        i = 0;
        int count_alpha(0), count_digit(0);
        bool is_alnum = true;
        while ( i != word.size() ) {
            if ( !isalnum(word[i]) ){
                is_alnum = false;;
                break;
            }
            if ( isalpha(word[i]) )
                count_alpha++;
            else if ( isdigit(word[i]) )
                count_digit++;
            i++;
        }
        if (is_alnum && count_alpha % 2 == 0 && count_digit % 2 == 1)
            passwords_lengths.push_back( word.size() );
    }

    if (!(passwords_lengths.empty()))
        return *max_element(passwords_lengths.begin(), passwords_lengths.end());

    return -1;
}

int main()
{
    string input = "test 5 a0A pass007 ?xy1";
    int sol = solution(input);
    cout << "test 5 a0A pass007 ?xy1 ? 7: " << sol << endl;

    input = "0";
    sol = solution(input);
    cout << "0 ? 1: " << sol << endl;

    return 0;
}
