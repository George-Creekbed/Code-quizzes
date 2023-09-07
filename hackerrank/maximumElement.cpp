#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMax' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

vector<int> getMax(vector<string> operations) {
    size_t sz;
    int query, x;
    stack<int> my_stack, aux_stack;
    priority_queue<int> my_heap;
    vector<int> ret;
    for (string& str : operations) {
        query = stoi(str, &sz);
        if (query == 3) {
            cout << my_heap.top() << '\n';
            ret.emplace_back(my_heap.top());
        } else if (query == 2) {
            while (my_heap.top() != my_stack.top()) {
                aux_stack.emplace(my_heap.top());
                my_heap.pop();
            }
            my_stack.pop();
            my_heap.pop();
            while (!aux_stack.empty()) {
                my_heap.emplace(aux_stack.top());
                aux_stack.pop();
            }
        } else if (query == 1) {
            x = stoi(str.substr(sz));
            my_stack.emplace(x);
            my_heap.emplace(x);  
        }    
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> ops(n);

    for (int i = 0; i < n; i++) {
        string ops_item;
        getline(cin, ops_item);

        ops[i] = ops_item;
    }

    vector<int> res = getMax(ops);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
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
