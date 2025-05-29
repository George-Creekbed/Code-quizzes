#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

// int palindromeIndex(string s) {
//     int end = s.size()-1;
//     int mid = s.size()/2;
//     if (s.size() % 2 == 1)
//         s.erase(mid, 1);
//     int counter(0), ret(-1);
//     map<char, int> map_chars;
//     for (auto c : s)
//         ++map_chars[c];  
//     if (map_chars.size() == 1)
//         return -1;
//     else
//         for (auto pairr : map_chars) {
//             if (pairr.second % 2 == 1)
//                 ++counter;
//         }  
//     if (counter == 0 || counter % 2 == 1)
//         return -1;
//     counter = 0;
//     for (int i = 0; i != mid; ++i) {
//         if (s[i] != s[end-i]) {
//             if (map_chars[s[i]] == 1){
//                 ret = i;
//             } else if (map_chars[s[end-i]] == 1){
//                 ret = end-i;
//             } else if (map_chars[s[i]] % 2== 1){
//                 ret = i;
//             } else if (map_chars[s[end-i]] % 2 == 1){
//                 ret = end-i; 
// 			}
//             counter++;
//         }
// 	}
// 	return ret;
// }

bool isPalindrome(string s){
     string r = s;
     reverse(r.begin(), r.end());
     return s == r;
 }

int palindromeIndex(string input) {
    int s, e;
    for(s = 0, e = input.size() - 1; s < e; s++, e--){
        if(input[s] != input[e]) break;
    }
    if(s >= e) return -1;
    string s1 = input, s2 = input;
    s1.erase(s1.begin() + s);
    if(isPalindrome(s1)) return s;
    s2.erase(s2.begin() + e);
    if(isPalindrome(s2)) return e;
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

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
