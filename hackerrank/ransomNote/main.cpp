#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_multiset<string> words;
    for_each(magazine.begin(), magazine.end(),
             [&](const string& in) {
                 words.insert(in);
             });

    unordered_map<string, unsigned> map_count;
    for (string ii : note) {
        auto current_word_count = words.equal_range(ii);
        if (current_word_count.first == words.end()) {
            cout << "No" << endl;
            return;
        } else if (current_word_count.first != current_word_count.second) {
            map_count[ii]++;
            if (words.count(ii) < map_count[ii]) {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
}


int main()
{
    vector<string> input_mag = {"give", "me", "one", "grand", "today", "night"};
    vector<string> input_note = {"give", "one", "grand", "today"};
    cout << "Words in the magazine:       ";
    for (string ii : input_mag)
        cout << " " << ii;
    cout << endl;
    cout << "Words to put inside the note:";
    for (string ii : input_note)
        cout << " " << ii;
    cout << endl;
    cout << "Can the note be composed out of words in the magazine ? Yes: ";
    checkMagazine(input_mag, input_note);
    cout << endl;

    input_mag = {"two", "times", "three", "is", "not", "four"};
    input_note = {"two", "times", "two", "is", "four"};
    cout << "Words in the magazine:       ";
    for (string ii : input_mag)
        cout << " " << ii;
    cout << endl;
    cout << "Words to put inside the note:";
    for (string ii : input_note)
        cout << " " << ii;
    cout << endl;
    cout << "Can the note be composed out of words in the magazine ? No: ";
    checkMagazine(input_mag, input_note);
    cout << endl;

    return 0;
}
