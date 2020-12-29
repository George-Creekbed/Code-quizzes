#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string minString(const string& minimum, const string& maximum) {
    unordered_map<char,int> char_map;
    for (auto ii : minimum)
            char_map[ii]++;
        for (auto jj : maximum) {
            if (char_map[jj] > 0)
                return "YES";
        }

    return "NO";
}

string twoStrings(string s1, string s2) {
    string::size_type smaller = min(s1.size(), s2.size());
    if (smaller == s1.size())
        return minString(s1, s2);
    else
        return minString(s2, s1);
}


int main()
{
    string input0 = "hello";
    string input1 = "world";
    string sol = twoStrings(input0, input1);
    cout << "hello world! YES: " << sol << endl;

    input0 = "hi";
    input1 = "world";
    sol = twoStrings(input0, input1);
    cout << "hi world! NO: " << sol << endl;
    return 0;
}
