#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */
void divideNConquer(vector<int>& myvec, unsigned& inversions) {
    if (myvec.size() > 2) {
        unsigned half_size = myvec.size() / 2;
        vector<int> demi_a(half_size), demi_b(half_size);
        myvec.size() % 2 == 1? demi_a.resize(half_size+1): void();
        copy(myvec.begin(), myvec.begin() + demi_a.size(), demi_a.begin());
        copy(myvec.begin()+demi_a.size(), myvec.end(), demi_b.begin());
        if (demi_a.size()>1)
            divideNConquer(demi_a, inversions);
        if (demi_b.size()>1)
            divideNConquer(demi_b, inversions);
//        DEBUG
//        ostream_iterator<int> print_it(cout, " ");
//        copy(demi_a.begin(), demi_a.end(), print_it);
//        cout << '\n';
//        copy(demi_b.begin(), demi_b.end(), print_it);
        int i = 0, j = 0;
        for (int k = 0; k != myvec.size(); ++k) {
            if ( (i < demi_a.size()) && 
                 ((j >= demi_b.size()) || (demi_a[i] <= demi_b[j])) ) {
                myvec[k] = demi_a[i];
                i++;
            } else if (j < demi_b.size()) {
                myvec[k] = demi_b[j];
                j++;
                if (i < demi_a.size())
                    inversions += demi_a.size() - i;
            }
        }
//        DEBUG
//        cout << '\n';
//        copy(myvec.begin(), myvec.end(), print_it);
//        cout << '\n';
    }
    if (myvec.size() == 2) {
        if (myvec[0] > myvec[1]) {
            ++inversions;
            swap(myvec[0], myvec[1]);
        }
    }       
}

void minimumBribes(vector<int> q) {
    unsigned bribes{0};
    vector<int> copy_q(q);
    for (int i = 0; i != q.size(); ++i) {
        if (q[i]-i-1 > 2) {
            cout << "Too chaotic\n";
            return;
        }
    }  
    divideNConquer(q, bribes);    
    cout << bribes << '\n';    
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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
