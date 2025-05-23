#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    const unsigned alphabet_width{26};
    string ret{};
    set<char> chars_in_s;
    for (char c : s) {
        if (isalpha(c)) {
            if (isupper(c)) {
                c = tolower(c);
            }
            chars_in_s.insert(c);
        }
    }
    chars_in_s.size() == alphabet_width ?
        ret = "pangram" :
        ret = "not pangram";
    
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
