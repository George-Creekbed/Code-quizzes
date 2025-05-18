// most difficult problem found on hackerrank (and elsewhere) so far
// adapted solution from http://blog.5digits.org/2025/01/25/how-to-solve-lego-blocks-on-hackerrank/
// positive would have never been able to solve this task without it
// I mean mathematically I got to the permutation total as line_permutations^n
// but would never have guessed the vertical-break-as-separator-between-2-subwalls algorithm
// also the specialised modulo functions and their repeated application inside the solver function
// would never have discovered that as the source of test failings
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'legoBlocks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */
constexpr long MOD = 1e9 + 7;

long mod(long val, long div) {
    long res = val % div;
    if (res < 0) {
        res += div;
    }
    return res;
}

long powMod(long base, long exp) {
    long result = base;
    for (int i = 1; i < exp; i++) {
        result = mod(result * base, MOD);
    }
    return result;
}


int legoBlocks(int n, int m) {

    // 1. number of permutations for a line of length m
    // line is formed with any combination of the four blocks at disposal (block lengths = 1, 2, 3 and 4)
    vector<long> line_permutations(m+1);
    line_permutations[0] = 1;
    for (auto i=1; i!=5; ++i) {
        if (i <= m)
            line_permutations[i] = static_cast<int>(pow(2, i-1));
        else break;
    }
    if (m > 4) {
        for (auto i=5; i!=m+1; ++i) {
            line_permutations[i] = mod(
                accumulate(
                    line_permutations.cbegin()+i-4, 
                    line_permutations.cbegin()+i,
                    0L  // L very important here, try without and see
                ), 
                MOD
            );
        } 
    }
    
    // 2. knowing permutations for one line of length m,
    // compute permutations for the whole wall of height n
    // made of stacked lines of length m
    vector<long> wall_permutations(m+1);
    // cout << endl;
    // cout << "New test:\n";
    for (auto i=0; i!=m+1; ++i) {
        wall_permutations[i] = powMod(line_permutations[i], n);
        // cout << i << " - line permutations: " << line_permutations[i];
        // cout << "  - wall permutations: " << wall_permutations[i] << endl;
    }
    
    // 3. straight vertical breaks in the wall equal to two adjacent
    // walls with lengths that sum to m
    vector<long> vertical_breaks(m+1);
    for (auto i=0; i!=m+1; ++i) {
        long aux{};
        for (auto j=1; j<i; ++j) {
            long valid_configs_left = wall_permutations[j] - vertical_breaks[j];
            aux += mod(valid_configs_left * wall_permutations[i-j], MOD);
            // cout << "iteration " << i << "-" << j << " valid conf left: " 
                // << valid_configs_left << " - aux: " << aux << endl;
        }
        vertical_breaks[i] = mod(aux, MOD);
        // cout << "iteration: " << i << " - vertical breaks: " << vertical_breaks[i] << endl;
    }
    
    return mod((wall_permutations[m] - vertical_breaks[m]), MOD);
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = legoBlocks(n, m);

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
