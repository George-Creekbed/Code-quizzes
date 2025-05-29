#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<bool> is_visited(n, false);
    is_visited[s-1] = true;
    queue<int> traversed;
    traversed.emplace(s);
    
    vector<int> ret(n-1, 0); 
    int count_visited{};
    int weighted_distance{6};
    while (count_visited < n-1) {
        cout << "count_visited: " << count_visited << endl;
        while (!traversed.empty()) {
            int current{traversed.front()};
            cout << "current: " << current << endl;
            cout << "ret: \n"; 
            for (auto& item : ret) {
                cout << item << " ";
            }
            cout << endl;
            for (const auto& edge : edges) {
                if (edge[0] == current) {
                    if (!is_visited[edge[1]-1]) {
                        is_visited[edge[1]-1] = true;
                        count_visited += 1;
                        traversed.emplace(edge[1]);
                        if (current == s) {
                            if (edge[1] < s)
                                ret[edge[1]-1] = weighted_distance;
                            else
                                ret[edge[1]-2] = weighted_distance;   
                        } else {
                            if (edge[1] < s) {
                                if (current < s)
                                    ret[edge[1]-1] = ret[current-1] + weighted_distance;
                                else
                                    ret[edge[1]-1] = ret[current-2] + weighted_distance;
                            } else {
                                if (current < s)
                                    ret[edge[1]-2] = ret[current-1] + weighted_distance;
                                else
                                    ret[edge[1]-2] = ret[current-2] + weighted_distance;
                            }
                        }
                    }
                } else if (edge[1] == current) {
                    if (!is_visited[edge[0]-1]) {
                        is_visited[edge[0]-1] = true;
                        count_visited += 1;
                        traversed.emplace(edge[0]);
                        if (current == s) {
                            if (edge[0] < s)
                                ret[edge[0]-1] = weighted_distance;
                            else
                                ret[edge[0]-2] = weighted_distance;   
                        } else {
                            if (edge[0] < s) {
                                if (current < s)
                                    ret[edge[0]-1] = ret[current-1] + weighted_distance;
                                else
                                    ret[edge[0]-1] = ret[current-2] + weighted_distance;
                            } else {
                                if (current < s)
                                    ret[edge[0]-2] = ret[current-1] + weighted_distance;
                                else
                                    ret[edge[0]-2] = ret[current-2] + weighted_distance; 
                            }
                        }                  
                    }
                }
            }
            auto removed_iter = remove_if(
                edges.begin(), 
                edges.end(), 
                [&current](const vector<int>& a){
                    return (a[0]==current || a[1]==current);
                }
            );
            if (removed_iter != edges.end()) {
                edges.resize(distance(edges.begin(), removed_iter));
                // weighted_distance += 6;
            }
            traversed.pop();
        }
        auto still_not_visited_iter = find(is_visited.begin(), is_visited.end(), false);
        if (still_not_visited_iter != is_visited.end()) {
            long this_el{distance(is_visited.begin(), still_not_visited_iter)};
            if (this_el+1 < s)
                ret[this_el] = -1;
            else
                ret[this_el-1] = -1;
            *still_not_visited_iter = true;
            count_visited += 1;
        }
    }
    cout << "count_visited at end function: " << count_visited << endl;
    cout << "ret: \n";
    for (auto& i : ret) {
        cout << i << " ";
    }
    cout << endl;
    
    return ret;
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

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
