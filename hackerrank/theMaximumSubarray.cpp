#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maxSubarray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
vector<int> maxSubarray(vector<int> arr) {
    const size_t size = arr.size();
    if (size == 1)
        return vector<int>{arr[0], arr[0]};
 
    vector<int> ans(2);
    int max_total{INT_MIN}, max_local{}, max_el{INT_MIN};

    for (auto f=0; f!=size; ++f) {
        max_local = max(max_local + arr[f], arr[f]);
        max_total = max(max_total, max_local);

        max_el = max(max_el, arr[f]);
        if (arr[f] > 0) {
            ans[1] += arr[f];
        }
    }
    ans[0] = max_total;
    if (max_el <= 0) {
        ans[1] = max_el;
    }
    
    return ans;
}

// old solution, too slow
// vector<int> maxSubarray(vector<int> arr) {
//     size_t size = arr.size();
//     if (size == 1)
//         return vector<int>{arr[0], arr[0]};
 
//     vector<int> ans(2);
//     int caterpillar_total{}, max_total{INT_MIN};
    
//     for (auto i=0; i!=size; ++i) {
//         for (auto f=i; f!=size; ++f) {
//             caterpillar_total += arr[f];
//             max_total = max(max_total, caterpillar_total);
//         }
//         caterpillar_total = 0;
//     }
//     ans[0] = max_total;
    
//     sort(arr.begin(), arr.end());
//     if (*(arr.end()-1) > 0) {
//         auto smallest_positive_iter = upper_bound(arr.begin(), arr.end(), 0);
//         ans[1] = accumulate(smallest_positive_iter, arr.end(), 0);
//     } else {
//         ans[1] = *(arr.end()-1);
//     }
    
//     return ans;
// }

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

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        vector<int> result = maxSubarray(arr);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
