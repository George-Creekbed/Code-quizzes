#include <bits/stdc++.h>
<<<<<<< HEAD
#include <numeric>
#include <utility>
=======
>>>>>>> 93db7f99393b148b58e1b97ad739fbdcda7b4bbc

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
<<<<<<< HEAD
=======

>>>>>>> 93db7f99393b148b58e1b97ad739fbdcda7b4bbc
/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(vector<int> arr) {
<<<<<<< HEAD
    vector<int> adjacent_diff(arr.size());
    adjacent_difference(arr.begin(), arr.end(), adjacent_diff.begin());
    int result{0};
    for (size_t i=0; i!=adjacent_diff.size(); ++i) {
        if (adjacent_diff[i] < 0) {
            auto my_iter = lower_bound(arr.begin(), arr.begin()+i, arr[i]);
=======
    /* the smallest sum of adjacent difference is found when the vector
       is sorted either in increasing or decreasing order */
    // reverse original input vector in view of second pass below
    vector<int> arr_copy(arr.size());
    reverse_copy(arr.begin(), arr.end(), arr_copy.begin());
    // So, first pass comparison against increasingly sorted vector:   
    int result{0};
    vector<int> arr1(arr);
    sort(arr1.begin(), arr1.end());
    for (size_t i=0; i!=arr.size(); ++i) {
        if (arr[i] != arr1[i]) {
            auto my_iter = find(arr.begin()+i, arr.end(), arr1[i]);
            // "arr.begin()+i" makes the above 'find' less than o(n) 
            // and crucially saves complexity
>>>>>>> 93db7f99393b148b58e1b97ad739fbdcda7b4bbc
            swap(*my_iter, arr[i]);
            ++result;
        }
    }
<<<<<<< HEAD
    return result;
=======
    // second pass is a comparison against decreasingly sorted input vector:
    int reverse_result{0};
    for (size_t i=0; i!=arr_copy.size(); ++i) {
        if (arr_copy[i] != arr1[i]) {
            auto my_iter = find(arr_copy.begin()+i, arr_copy.end(), arr1[i]);
            swap(*my_iter, arr_copy[i]);
            ++reverse_result;
        }
    }

    return min(result, reverse_result);
>>>>>>> 93db7f99393b148b58e1b97ad739fbdcda7b4bbc
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    int result = lilysHomework(arr);

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

<<<<<<< HEAD
    return tokens;
}
=======
    return tokens;}
>>>>>>> 93db7f99393b148b58e1b97ad739fbdcda7b4bbc
