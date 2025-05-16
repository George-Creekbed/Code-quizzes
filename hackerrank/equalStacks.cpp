#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    size_t h1_size{h1.size()}, h2_size{h2.size()}, h3_size{h3.size()};
    vector<int> sums_h1(h1_size), sums_h2(h2_size), sums_h3(h3_size);
    
    partial_sum(h1.rbegin(), h1.rend(), sums_h1.begin());
    partial_sum(h2.rbegin(), h2.rend(), sums_h2.begin());
    partial_sum(h3.rbegin(), h3.rend(), sums_h3.begin());
    
    // cout << "sums h1: " << endl;
    // for (auto item : sums_h1)
    //     cout << item << " ";
    // cout << endl;
    // cout << "sums h2: " << endl;
    // for (auto item : sums_h2)
    //     cout << item << " ";
    // cout << endl;
    // cout << "sums h3: " << endl;
    // for (auto item : sums_h3)
    //     cout << item << " ";
    // cout << endl;
    
    auto iter1{sums_h1.rbegin()}, iter2{sums_h2.rbegin()}, iter3{sums_h3.rbegin()};
    size_t s1{h1_size}, s2{h2_size}, s3{h3_size};
    
    if (*iter1 == *iter2) {
        if (*iter2 == *iter3) {
            return *iter1;
        }
    }
    
    while (s1 > 0 && s2 > 0 && s3 > 0) {
        // cout << "iteration." << endl;
        // cout << "iter1: " << *iter1 << endl;
        // cout << "iter2: " << *iter2 << endl;
        // cout << "iter3: " << *iter3 << endl;
        if (
            (max(*iter1, max(*iter2, *iter3)) == *iter1) 
            && 
            (
                (*iter1 != *iter2 && *iter1 != *iter3)
                ||
                (*iter1 == *iter2 && s1 >= s2 && *iter1 != *iter3)
                ||
                (*iter1 == *iter3 && s1 >= s3 && *iter1 != *iter2)
            )
        ) {
            ++iter1;
            --s1;
        }
        else if (
            (max(*iter1, max(*iter2, *iter3)) == *iter2) 
            &&
            (
                (*iter2 != *iter3)
                ||
                (*iter2 == *iter3 && s2 >= s3)
            )
        ) {
            ++iter2;
            --s2;
        }
        else if (max(*iter1, max(*iter2, *iter3)) == *iter3) {
            ++iter3;
            --s3;
        };

        if (*iter1 == *iter2) {
            if (*iter2 == *iter3) {
                return *iter1;
            }
        }
    }; 
    
    return 0;  
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split(rtrim(h1_temp_temp));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split(rtrim(h2_temp_temp));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split(rtrim(h3_temp_temp));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

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