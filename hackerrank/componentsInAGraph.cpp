#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'componentsInGraph' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY gb as parameter.
 */
bool mapLess(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

vector<int> componentsInGraph(vector<vector<int>> gb) {
    size_t n{gb.size()};
    map< int, set<int> > neighbours;
    for (const auto& edge : gb) {
        int node{edge[0]};
        neighbours[node].emplace(edge[1]);
        neighbours[edge[1]].emplace(node);
    }
    
    queue<int> traversed;
    traversed.emplace(1);
    vector<bool> is_visited(2*n, false);
    map<int, int> graphs;
    
    while (find(is_visited.begin(), is_visited.end(), false) != is_visited.end()) {
        int head{-1};
        while (!traversed.empty()) {
            int current{traversed.front()};            
            if (!neighbours[current].empty() && !is_visited[current-1]) {
                head = current;
                graphs[current]++;
            } else if (neighbours[current].empty()) {
                is_visited[current-1] = true;
                traversed.pop();
                break;
            }
            
            cout << "current: " << current << " - head: " << head << endl;
            cout << "current neighbours: \n"; 
            for (auto& node : neighbours[current]) {
                cout << node << " ";
            }
            cout << endl;
            
            for (const auto& node : neighbours[current]) {
                if (!is_visited[node-1]) {
                    graphs[head]++;
                    is_visited[node-1] = true;
                    traversed.emplace(node);
                }
            }
            cout << "graphs head: " << head << " - " << graphs[head] << endl;
            
            if (!is_visited[current-1]) {
                is_visited[current-1] = true;
            }
            traversed.pop();
        }
        auto next_node_iter = find(is_visited.begin(), is_visited.end(), false);
        if (next_node_iter != is_visited.end()) {
            long next_node{distance(is_visited.begin(), next_node_iter) + 1};
            traversed.emplace(next_node);
        }
    }
    
    return vector<int> {
        min_element(graphs.begin(), graphs.end(), mapLess)->second, 
        max_element(graphs.begin(), graphs.end(), mapLess)->second
    };
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> gb(n);

    for (int i = 0; i < n; i++) {
        gb[i].resize(2);

        string gb_row_temp_temp;
        getline(cin, gb_row_temp_temp);

        vector<string> gb_row_temp = split(rtrim(gb_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int gb_row_item = stoi(gb_row_temp[j]);

            gb[i][j] = gb_row_item;
        }
    }

    vector<int> result = componentsInGraph(gb);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
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
