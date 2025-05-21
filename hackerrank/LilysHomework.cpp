#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(vector<int> arr) {
    // make a copy of arr for the reverse pass
    vector<int> arr_copy(arr.size());
    reverse_copy(arr.begin(), arr.end(), arr_copy.begin());
    
    // So, first pass comparison against increasingly sorted vector:   
    int result{};
    vector<int> arr1(arr);
    sort(arr1.begin(), arr1.end());
    // cout << "direct: " << endl;
    for (size_t i=0; i!=arr.size(); ++i) {
        // for (auto item : arr)
        //     cout << item << " ";
        // cout << endl;
        if (arr[i] != arr1[i]) {
            auto my_iter = find(arr.begin()+i, arr.end(), arr1[i]);
            // "arr.begin()+i" makes the above 'find' less than o(n) 
            // and crucially saves complexity
            swap(*my_iter, arr[i]);
            ++result;
        }
    }
    // second pass is a comparison against decreasingly sorted input vector:
    int reverse_result{};
    // cout << "reverse: " << endl;
    for (size_t i=0; i!=arr_copy.size(); ++i) {
        // for (auto item : arr_copy)
        //     cout << item << " ";
        // cout << endl;
        if (*(arr_copy.begin()+i) != arr1[i]) {
            auto my_iter = find(arr_copy.begin()+i, arr_copy.end(), arr1[i]);
            swap(*my_iter, *(arr_copy.begin()+i));
            ++reverse_result;
        }
    }

    return min(result, reverse_result);
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

    return tokens;
}
