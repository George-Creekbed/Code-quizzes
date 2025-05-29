// solution too slow, not achieving full points
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */
bool isFalse(bool a) {
    return a == false;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    if (c_lib <= c_road || cities.empty()) {
        return n * c_lib;
    }
    
    vector<bool> is_explored(n, false);
    queue<int> traversed;
    traversed.emplace(1);
    is_explored[0] = true;
    int count_explored{1};
    
    sort(cities.begin(), cities.end());
    
    long libraries{1};
    while (count_explored != n) {
    // while (any_of(is_explored.begin(), is_explored.end(), isFalse)) {
        while (!traversed.empty()) {
            int current{traversed.front()};
            // function<void (const vector<int>&) > broadFirstSearch =
            //     [&current, &traversed, &is_explored, &count_explored](const vector<int>& a) {
            //         if (a[0] == current) {
            //             if (!is_explored[a[1]-1]) {
            //                 traversed.emplace(a[1]);
            //                 is_explored[a[1]-1] = true;
            //                 ++count_explored;
            //             }
            //         } else if (a[1] == current) {
            //             if (!is_explored[a[0]-1]) {
            //                 traversed.emplace(a[0]);
            //                 is_explored[a[0]-1] = true;
            //                 ++count_explored;
            //             }
            //         }
            //     }
            // ;
            // for_each(cities.begin(), cities.end(), broadFirstSearch);

            function<bool (const vector<int>&) > broadFirstSearchErase =
                [&current, &traversed, &is_explored, &count_explored](const vector<int>& a) {
                    // exploit side effect!
                    if (a[0] == current) {
                        if (!is_explored[a[1]-1]) {
                            traversed.emplace(a[1]);
                            is_explored[a[1]-1] = true;
                            ++count_explored;
                        }
                    } else if (a[1] == current) {
                        if (!is_explored[a[0]-1]) {
                            traversed.emplace(a[0]);
                            is_explored[a[0]-1] = true;
                            ++count_explored;
                        }
                    }
                        
                    return (a[0] == current || a[1] == current);
                }
            ;
            auto removed_iters = remove_if(
                cities.begin(), 
                cities.end(), 
                broadFirstSearchErase
            );
            cities.resize(distance(cities.begin(), removed_iters));

            traversed.pop();
        }
        // auto iter = find(is_explored.begin(), is_explored.end(), false);
        // if (iter != is_explored.end()) {
        if (count_explored != n) {

            auto iter = find(is_explored.begin(), is_explored.end(), false);
            traversed.emplace(distance(is_explored.begin(), iter)+1);
            *iter = true;
            ++count_explored;
            ++libraries;
        }          
    } 
    
    return libraries * c_lib + (n-libraries) * c_road;   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

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
