#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'substrCount' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING s
 */

long substrCount(int n, string s) {
    // caterpillar
    int start{0}, stop{1};
    long result{n};
    while (start != n) {
        int yes_counter_left{1}, no_counter{0}, yes_counter_right{0};
        while (stop < n) {
            if (no_counter == 0) {
                s[start] == s[stop] ? ++yes_counter_left : ++no_counter;
                if (yes_counter_left > 1 && no_counter == 0)
                    ++result;
            } else if (no_counter == 1) {
                s[start] == s[stop] ? ++yes_counter_right : ++no_counter;
                if (yes_counter_left == yes_counter_right && no_counter == 1) {
                    ++result;
                    ++stop;
                    break;
                }
            } else {
                ++stop;
                break;
            }
            ++stop;
        }
        ++start;
        stop = start + 1;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

