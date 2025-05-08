#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sumXor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long sumXor(long n) {
    if (n==0) {
        return 1;
    }
    
    // exploit the fact that wanted result is =
    // = 2^(number of 0s in binary representation of n)
    bitset<64> n2(n);
    size_t counter_0s{};
    for (auto idx=0; idx!=floor(log2(n))+1; ++idx) {
        if (n2[idx] == 0)
            counter_0s++;
    }

    return pow(2, counter_0s);
    
    // slower more methodical solution:
    // if (n==0) {
    //     return 1;
    // }
    // bitset<64> n2(n);
    // if (n2.count() == 1) {
    //     counter += n;
    // } else {
    //     for (auto x=0; x!=n; x++) {
    //         bitset<64> x2(x);
    //         size_t length_x2{};
    //         for (auto i=0; i!=floor(log2(n))+1; ++i) {
    //             if (x2.test(i))
    //                 length_x2 = i+1;
    //         }
    //         bool flag{true};
            
    //         for (auto i=0; i!=length_x2; ++i) {
    //             if (x2[i] && n2[i]) {
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         if (flag)
    //             counter++;
    //         cout << "x2: " << x2 << " length_x2: " 
    //             << length_x2 << " counter: " 
    //             << counter << endl;
    //     }
    // }
    // return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = sumXor(n);

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
