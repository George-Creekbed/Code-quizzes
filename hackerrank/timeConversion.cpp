#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string result;
    if (s.compare(8, 1, "P") == 0) 
        if (s.compare(0, 2, "12") == 0)
            result = "12" + s.substr(2, 6);
        else {
            string::size_type sz;
            int hours = stoi(s, &sz) + 12;
            result = to_string(hours) + s.substr(2, 6);
        }
    else if (s.compare(8, 1, "A") == 0) {
        if (s.compare(0, 2, "12") == 0)
            result = "00" + s.substr(2, 6);
        else
            result = s.substr(0, 8);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
