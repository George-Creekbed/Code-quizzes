#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */

void noPrefix(vector<string> words) {
    set<string> set_;    
    for (const string& item : words) {
        if (!set_.empty()) {
            auto lower_bound = set_.lower_bound(item);
            // cout << item << ", lower bound: " << *lower_bound << endl;
            if (
                lower_bound != set_.end() && 
                (lower_bound->size() >= item.size()) && 
                lower_bound->compare(0, item.size(), item) == 0
            ) {
                cout << "BAD SET\n" << item << endl;
                return;
            }
            set<string>::iterator upper_bound; 
            if (lower_bound != set_.begin())
                upper_bound = --lower_bound;
            else
                upper_bound = set_.end();
            // cout << "upper bound: " << *upper_bound << endl;
            if (
                upper_bound != set_.end() && 
                (item.size() >= upper_bound->size()) && 
                item.compare(0, upper_bound->size(), *upper_bound) == 0
            ) {
                cout << "BAD SET\n" << item << endl;
                return;
            } 
        }
        set_.emplace(item);   
    }
    
    cout << "GOOD SET\n";
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

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
