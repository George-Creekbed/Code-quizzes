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
// matrix dp slots[i][j] below get filled with true when scenarios with chars < (a[i], b[j]) follow the two rules and hence are still in the game
// abbreviation is successful (return "YES") in case the two strings can be both erased, ie last slot in dp is true.
    vector<vector<bool>> dp(a.size()+1, vector<bool>(b.size()+1, false));
    dp[0][0] = true;
    for (size_t i = 0; i != dp.size(); ++i) {
        for (size_t j = 0; j != dp[i].size(); ++j) {
            if (dp[i][j] == true) {
                if (toupper(a[i]) == b[j] && j < b.size())
                    dp[i+1][j+1] = true;
                if (islower(a[i]))
                    dp[i+1][j] = true;
            }   
        }
    }  
    return dp.back().back() == true ? "YES" : "NO";     
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

