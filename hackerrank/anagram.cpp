#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
    size_t length{s.size()};
    if (length % 2 == 1)
        return -1;
    
    size_t mid{length/2};
    string s1{s.substr(0, mid)}, s2{s.substr(mid, mid)};
    unordered_map<char, int> s1_chars, s2_chars;
    for_each(s1.begin(), s1.end(), [&s1_chars](const char& c){s1_chars[c]++;});
    for_each(s2.begin(), s2.end(), [&s2_chars](const char& c){s2_chars[c]++;});

    string alphabet{"abcdefghijklmnopqrstuvwxyz"};
    int count{};
    for (char c : alphabet) {
        if (s1_chars[c] - s2_chars[c] > 0) {
            count += s1_chars[c] - s2_chars[c];
        }
    }
    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

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
