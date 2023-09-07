#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'stockmax' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY prices as parameter.
 */

long stockmax(vector<int> prices) {
    /* dp:    rows: elements in input vector 'prices'      *
     *     columns: number of possible stocks in portfolio *
     * each slot in dp is a set of possible portfolio      *
     * values up to that time (time = element in prices)   */ 
    int size = prices.size();     
    vector< vector< set<long>>> dp(size, vector<set<long>>(size + 1));
    
    dp[0][0].emplace(0);
    dp[0][1].emplace(-prices[0]);
    ostream_iterator<long> os(cout, " ");
    for (int i = 0; i != size - 1; ++i) {
        for (int j = 0; j != i + 2; ++j) {
            for (const long& k : dp[i][j]) {
                for (int l = j; l != 0; --l)
                    dp[i+1][j-l].emplace(k + l * prices[i+1]);
                dp[i+1][j].emplace(k);
                dp[i+1][j+1].emplace(k - prices[i+1]);
            }
            cout << "dp[" << i << "][" << j << "]: ";
            copy(dp[i][j].begin(), dp[i][j].end(), os);
            cout << '\n';
        }
    }
    int col{0};
    for_each(dp[size-1].begin(), dp[size-1].end(),
        [&](set<long>& my_set) {
            cout << "dp[" << size << "][" << col++ << "]: ";
            copy(my_set.begin(), my_set.end(), os);
            cout << '\n';
        }
    );
    cout << "-------------------\n";

    long max_profit{0};
    for (set<long>& slot : dp[size-1]) {
        set<long>::reverse_iterator iter = slot.rbegin();//prev(slot.end());
        long local_max = *(iter);
        max_profit = max(max_profit, local_max);
    }
    return max_profit;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string prices_temp_temp;
        getline(cin, prices_temp_temp);

        vector<string> prices_temp = split(rtrim(prices_temp_temp));

        vector<int> prices(n);

        for (int i = 0; i < n; i++) {
            int prices_item = stoi(prices_temp[i]);

            prices[i] = prices_item;
        }

        long result = stockmax(prices);

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

