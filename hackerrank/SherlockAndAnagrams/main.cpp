//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int sherlockAndAnagrams(string s) {
    int len = s.size();
    unordered_map<string, int> my_map;  //map hosting substrings of s and their frequency
    int j = 1;       // j are number of adjacent characters for current caterpillar pass on s
    // perform a caterpillar pass on s, each time with increasing j
    while (j < len) {
        int beg = 0;       // start at first char in s
        // loop for caterpillar pass
        while (beg != len - j + 1) {   // stop at last chunk of j chars in s
            string i = s.substr(beg, j);  // i is the chunk
            sort(i.begin(), i.end());  // we want i sorted so that ...
            if (my_map.count(i))
                ++my_map[i];    // ... so that my_map.second will increase with each anagram
            else
                my_map.emplace(make_pair(i, 1));  // if chunk i was not registered, register it
            ++beg;
            //cout << i << " " << my_map[i] << endl;  // debug
        }
        ++j;  // increase chunk size
    }

    int result = 0;
    // total number of anagrams is (i.second - 1) + (i.second - 2) + ... + 1
    // the following could be made into its own function countAnagrams() for readibility
    for (auto i : my_map) {
        if (i.second > 1) {
            int result_i = 0;
            while (i.second > 0)
                result_i += (i.second-- - 1);
            result += result_i;
        }
    }

    return result;
}

int main()
{
   // ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        //fout << result << "\n";
        cout << result << "\n";
    }

    //fout.close();

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
