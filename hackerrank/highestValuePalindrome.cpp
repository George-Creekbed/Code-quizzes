#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'highestValuePalindrome' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER n
 *  3. INTEGER k
 */

string highestValuePalindrome(string s, int n, int k) {
    int counter{}, mid_s{n/2};
    auto r_it=s.rbegin();
    for (auto it=s.begin(); it!=s.begin()+mid_s && r_it!=s.rbegin()+mid_s; ++it, ++r_it) {
        if (*it != *r_it) {
            counter++;
        }
    }
    if (counter > k) {
        return "-1";
    } else {
        r_it=s.rbegin();
        for (auto it=s.begin(); it!=s.begin()+mid_s && r_it!=s.rbegin()+mid_s && k>0; ++it, ++r_it) {
            // cout << "counter: " << counter << " - k: " << k << endl;
            if (counter < k && k > 1) {
                if (*it != *r_it) {
                    counter--;
                }
                if (*it != '9') {
                    *it = '9';
                    k--;
                }
                if (*r_it != '9') {
                    *r_it = '9';
                    k--;
                };
            } else if (counter == k && k > 0) {
                if (*it < *r_it) {
                    *it = *r_it;
                    k--;
                    counter--;
                } else if (*it > *r_it) {
                    *r_it = *it;
                    k--;
                    counter--;
                }           
            }
        }      
    }
    if (n % 2 == 1) {
        if (k > 0) {
            s[mid_s] = '9';
        }
    }
    
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
