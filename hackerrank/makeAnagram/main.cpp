#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int makeAnagram(string a, string b) {
    unordered_map<char, int> chars_in_a;
    int ret(0);

    for (const char& ii : a)
        chars_in_a[ii]++;
    for (const char& jj : b) {
        if (chars_in_a[jj] > 0)
            chars_in_a[jj]--;
        else
            ret++;
    }
    for (auto kk : chars_in_a)
        ret += kk.second;

    return ret;
}


int main()
{
    string input_a = "cde";
    string input_b = "dcf";
    cout << "Number of deletions needed to make " << input_a
         << " an anagram of " << input_b << " is 2: "
         << makeAnagram(input_a, input_b) << endl;

    input_a = "cde";
    input_b = "abc";
    cout << "Number of deletions needed to make " << input_a
         << " an anagram of " << input_b << " is 4: "
         << makeAnagram(input_a, input_b) << endl;

    return 0;
}
