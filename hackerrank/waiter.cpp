#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */
vector<int> sieveEratosthenes(int n) {
    const int threshold_for_1200_primes{10'000}; // see table 1 in https://t5k.org/howmany.html
    vector<bool> sieve(threshold_for_1200_primes, true);
    sieve[0] = sieve[1] = false;
    int i{2}, primes_found{};
    vector<int> answer;
    answer.reserve(n);
    while (primes_found < n) {
        if (sieve[i]) {
            answer.emplace_back(i);
            primes_found++;
            int k{i * i};
            while (k <= threshold_for_1200_primes) {
                sieve[k] = false;
                k += i;
            }
        }
        ++i;
    }
    
    return answer;
}

vector<int> waiter(vector<int> number, int q) {
    vector<int> primes = sieveEratosthenes(q);
    queue<int> A;
    for (auto i : number) {
        A.push(i);
    }
    stack<int> B;
    
    for (auto i=0; i!=q; ++i) {
        size_t size_A = A.size();
        for (auto j=0; j!=size_A; ++j) {
            if (A.front() % primes[i] == 0) {
                B.push(A.front());
            } else {
                A.push(A.front());
            }
            A.pop();
        }
        if (i != q-1) {
            size_A = A.size();
            while(!A.empty()) {
                B.push(A.front());
                A.pop();
            }
            while(A.size() != size_A) {
                A.push(B.top());
                B.pop();
            }
        }
    }
    while (!A.empty()) {
        B.push(A.front());
        A.pop();
    }
    vector<int> answer{};
    answer.reserve(B.size());
    while (!B.empty()) {
        answer.emplace_back(B.top());
        B.pop();
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
