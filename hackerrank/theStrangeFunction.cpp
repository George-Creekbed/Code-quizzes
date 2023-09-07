// Not optimal. This solution does not yield maximum points!

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximumValue' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

long maximumValue(vector<int> a) {
    // Return the maximum value of f among all subsegments .
    long maxx{0L};
    function<long (vector<int>::iterator&, vector<int>::iterator&)> 
    f = [](vector<int>::iterator& ll, vector<int>::iterator& rr) {
        auto l = ll; 
        auto r = rr;
        if ((l == r) || (l+1 == r))
            return 0L;
        long term1 = gcd(*l, *(l+1));
        for (auto iter = l+1; iter != r; ++iter) {
            term1 = gcd(term1, *iter);
        }
        long term2 = accumulate(ll, rr, 0L);
        term2 -= *max_element(ll, rr);
        
        return term1 * term2;
    };
    
    if (a.size() == 1)
        return 0L;
    for (auto l = a.begin(); l != a.end(); ++l) {
        for (auto r = l; r != a.end()+1; ++r) {
            maxx = max(maxx, f(l, r));
        }
    } 
    return maxx;   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    long result = maximumValue(a);

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
