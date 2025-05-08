#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */
int64_t lcm(vector<int> input) {
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    sort(input.begin(), input.end());
    map<int, int> divisors;
    for (int i : input) {
        vector<int> divisors_i;
        vector<int>::iterator j = primes.begin();
        while (i != 1) {
            if (i % *j == 0) {
                divisors_i.push_back(*j);
                i /= *j;
            } else 
                ++j;
            if (j == primes.end())
                break;
        }
        sort(divisors_i.begin(), divisors_i.end());
        for (int k : divisors_i) {
            int highest_multiple_k = count(divisors_i.begin(), divisors_i.end(), k);
            if (highest_multiple_k > divisors[k])
                divisors[k] = highest_multiple_k;
        }
    }    
       
    return accumulate(divisors.begin(), divisors.end(),int64_t(1),[](int64_t t, pair<int, int> item) {
            return t * pow(item.first, item.second);
    }); 
}

int gcd(vector<int> input) {
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    sort(input.begin(), input.end());
    map<int, int> divisors;
    for (int i : input) {
        vector<int> divisors_i;
        vector<int>::iterator j = primes.begin();
        while (i != 1) {
            if (i % *j == 0) {
                divisors_i.push_back(*j);
                i /= *j;
            } else 
                ++j;
            if (j == primes.end())
                break;
        }
        sort(divisors_i.begin(), divisors_i.end());
        bool flag_empty(0);
        if (divisors.empty())
            for (int k : divisors_i)
                divisors[k] = count(divisors_i.begin(), divisors_i.end(), k);
        else
            for (auto item = divisors.begin(); item != divisors.end(); ) { // no increment
                int current_n = count(divisors_i.begin(), divisors_i.end(), item->first);
                if (current_n == 0) {
                    divisors.erase(item++);
                    if (divisors.empty()) {
                        flag_empty = 1;
                        break;
                    }
                } else if (item->second > current_n)
                    item->second = current_n;
                ++item;                 
            }
        if (flag_empty)
            break;
    }    
    if (divisors.empty())
        divisors[1] = 1;
       
    return accumulate(divisors.begin(), divisors.end(),1,[](int t, pair<int, int> item) {
            return t * pow(item.first, item.second);
    });  
}

int getTotalX(vector<int> a, vector<int> b) {
    //cout << lcm(a) << endl;
    //cout << lcm(b) << endl;
    
    //cout << gcd(a) << endl;
    //cout << gcd(b) << endl;
    int64_t lcm_a = lcm(a);
    int gcd_b = gcd(b);
    
    vector<int> factors_in_common;
    for (int i = lcm_a; i <= gcd_b; i += int(lcm_a)) 
        if (gcd_b % i == 0)
            factors_in_common.push_back(i);
    
    return factors_in_common.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    fout << total << "\n";

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
