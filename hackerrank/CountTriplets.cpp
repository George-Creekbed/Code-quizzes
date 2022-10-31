#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    long result{0};
// //  caterpillar method: too slow
//     for (size_t i = 0; i != arr.size()-2; ++i) {
//         for (size_t j = i+1; arr[j] <= r * arr[i]; ++j) {
//             for (size_t k = j+1; arr[k] <= r * arr[j]; ++k)        
//                 if (arr[j] == r * arr[i] && arr[k] == r * arr[j])
//                     ++result;
//         }          
//     }
    size_t size{arr.size()};
    unordered_map<int, unordered_map<long, long> > my_map_left, my_map_right;
    for (int i = 0; i != size; ++i) {
        unordered_map<long, long> my_map_left_i, my_map_right_i;
        for_each(arr.begin(), arr.begin()+i, [&](long a){++my_map_left_i[a];});
        for_each(arr.begin()+i+1, arr.end(), [&](long a){++my_map_right_i[a];});
        my_map_left[i] = my_map_left_i;
        my_map_right[i] = my_map_right_i;
    }
    if (r == 1 && my_map_left.size() == my_map_right.size() == 1) {
        long t = size - 2;
        long u = t - 1;
        long v = u - 1;
        return (t * u * v) / 6;
    }
    for (int i = 0; i != size; ++i) {
        long u{0}, v{0};
        if (arr[i] % r == 0) {
            u = my_map_left[i].count(arr[i] / r) ? 
                my_map_left[i][arr[i]/r] : 0;
            v = my_map_right[i].count(arr[i] * r) ? 
                my_map_right[i][arr[i]*r] : 0;
        }
        cout << "u v: " << " " << u << " " << v << '\n';
        result += u * v;   
    }
    cout << " input size: " << arr.size() << '\n';
    
    return result;
}

/* 
long countTriplets(vector<long> arr, long r) {
    unordered_map<long, long> counts;
    unordered_map<long, long> tuples;
    
    long count = 0;
    for (long value : arr) {
        
        if (value % r == 0) {
            int predecessor = value / r;
            count += tuples[predecessor];
            if (counts[predecessor] > 0) {
                tuples[value] += counts[predecessor];
            }
        }
        
        counts[value]++;
    }
    
    return count;
}   
*/

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    fstream fs("input.txt");
    getline(fs, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(fs, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(arr_temp.size());

    for (int i = 0; i < arr_temp.size(); i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    cout << ans << "\n";

    //fout.close();

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
