#include <bits/stdc++.h>
#include <algorithm>
#include <tuple>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */
double computeMedian(const vector<int>& subarray, int d) {
    double median{0};
    if (d % 2 == 0)
        median = double(subarray[d/2-1] + subarray[d/2]) / 2;
    else
        median = subarray[d/2];
        
    return median;
}

int activityNotifications(vector<int> expenditure, int d) {
    if (expenditure.size() == d)
        return 0;
        
    int result{0}, start{0};
    // caterpillar vector
    vector<int> subarray(
        expenditure.begin()+start, expenditure.begin()+start+d
    );
    sort(subarray.begin(), subarray.end());
    double median = computeMedian(subarray, d);
    
    // caterpillar crawls across all input
    for (size_t i = d; i != expenditure.size(); ++i) {
        expenditure[i] >= (2 * median) ? ++result : 0;
        int taken_out = expenditure[start];
        int added = expenditure[i];
        
        vector<int>::iterator iter_takenout = lower_bound(subarray.begin(), subarray.end(), taken_out);
        // cout << "iter_takenout: " << *iter_takenout;
        subarray.erase(iter_takenout);
        vector<int>::iterator iter_added = lower_bound(subarray.begin(), subarray.end(), added);
        subarray.insert(iter_added, added);
        // cout << ", iter_added: " << *iter_added << '\n';
        
        median = computeMedian(subarray, d);
        ++start;
    }
    
    return result; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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

