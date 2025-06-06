#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'cutTheTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY data
 *  2. 2D_INTEGER_ARRAY edges
 */

void deepFirstSearch(const int start, map<int, set<int> >& input, map<int, set<int> >& output, vector<bool>& is_visited, vector<int>& data_input, vector<int>& output_sums) 
{
    for (auto child : input[start]) {
        if (!is_visited[child-1]) {
            is_visited[child-1] = true;
            output[start].emplace(child);
            deepFirstSearch(child, input, output, is_visited, data_input, output_sums);  
            output_sums[start-1] += output_sums[child-1];          
        }
    }
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    size_t n{data.size()};
    
    vector<bool> is_visited(n, false);
    is_visited[0] = true;
    // first coarse sift
    map<int, set<int> > children1;
    for (auto& edge : edges) {
        children1[edge[0]].emplace(edge[1]);
        children1[edge[1]].emplace(edge[0]);
    }
    
    map<int, set<int> > children2;
    vector<int> sums(data);
    // function below yields tree (children2) and sums for every subtree (sums) 
    deepFirstSearch(1, children1, children2, is_visited, data, sums);  
   
    vector< pair<int, int> > cut_sets(n);
    vector<int> ret(n);
    int answer{INT_MAX};
    // cout << "cut sets sums: \n";
    for (auto i=0; i!=n; ++i) {
        cut_sets[i] = {sums[i], sums[0] - sums[i]};
        ret[i] = abs(cut_sets[i].first - cut_sets[i].second);
        answer = min(answer, ret[i]);
        
        // cout << i << ": |" << cut_sets[i].first << " - " 
        //     << cut_sets[i].second << "| = " << ret[i] << endl;
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string data_temp_temp;
    getline(cin, data_temp_temp);

    vector<string> data_temp = split(rtrim(data_temp_temp));

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        int data_item = stoi(data_temp[i]);

        data[i] = data_item;
    }

    vector<vector<int>> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        edges[i].resize(2);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    int result = cutTheTree(data, edges);

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
