#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'counterGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */

string counterGame(long n) {
    unsigned counter{};
    bitset<64> n2(n);
    while (true) { 
        if (n2 == 1) {
            if (counter%2 == 0)
                return "Richard";
            else
                return "Louise";
        }
            
        if (n2.count() == 1) { // if n2 = power of 2, divide by 2
            n2 >>= 1;
        } 
        else {
            size_t biggest_bit_set{};
            for (auto i=0; i!=n2.size(); ++i) {
                if (n2.test(i))
                    biggest_bit_set = i;
            }
            bitset<64> closer_power_of_2{};
            closer_power_of_2.set(biggest_bit_set);
            
            n2 ^= closer_power_of_2;
        }
        counter++;
    }   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        string result = counterGame(n);

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
