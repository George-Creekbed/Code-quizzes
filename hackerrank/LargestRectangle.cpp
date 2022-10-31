#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'largestRectangle' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY h as parameter.
 */

long largestRectangle(vector<int> h) {
    stack<int> mystack{};
    queue<int> myqueue{};
    vector<int> rectangles(h);
    for (auto iter = h.begin(); iter != h.end(); ++iter) {
        if (!mystack.empty()) {
            while (!mystack.empty() && mystack.top() >= *iter) {
                rectangles[iter - h.begin()] += *iter;
                myqueue.emplace(mystack.top());
                mystack.pop();
            }
            while (!myqueue.empty()) {
                mystack.emplace(myqueue.front());
                myqueue.pop();
            }  
        }
        mystack.emplace(*iter);
    }
    stack<int>().swap(mystack);
    queue<int>().swap(myqueue);
    for (auto riter = h.rbegin(); riter != h.rend(); ++riter) {
        cout << *riter << '\n';
        if (!mystack.empty()) {
            while (!mystack.empty() && mystack.top() >= *riter) {
                rectangles[h.rend() - riter - 1] += *riter;
                myqueue.emplace(mystack.top());
                mystack.pop();
            }
            while (!myqueue.empty()) {
                mystack.emplace(myqueue.front());
                myqueue.pop();
            }  
        }
        mystack.emplace(*riter);
    }
    return *max_element(rectangles.begin(), rectangles.end());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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

