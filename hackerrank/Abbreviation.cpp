/** This solution doesn't solve all cases
 *  Dynamic Programming approach needed
 *  see Abbreviation_dp.cpp */
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

string abbreviation(string a, string b) {
//    string sub_a{""};
    size_t i{0}, j{0};
    while (i < a.size() || j < b.size()) {
        if (toupper(a[i]) == b[j]) {
//            sub_a += a[i];
            ++i;
            ++j;
        } else if (islower(a[i]))
            ++i;
        else
            return "NO";
        if (j == b.size()) {
            for (auto& c : a.substr(i)) 
                if (isupper(c))
                    return "NO";
            return "YES";
        }
//        cout << sub_a << '\n';
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

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

