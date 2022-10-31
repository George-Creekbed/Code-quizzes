#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */
vector<int> inOrderTraversal(vector<vector<int>> indexes) {
    stack<int> path;
    path.emplace(1);
    vector<int> output(indexes.size());
    // 'mask vector below is1-indexed as is simpler for stack elements directly, 
    // but not for their children in 'indexes'
    vector<bool> mask(indexes.size()+1, false); 
    mask[0] = true;
    size_t i{0};
    while (i != indexes.size()) {
        while(path.top() != -1) {
            int choice_node = path.top()-1; // indexes vector is 0-indexed
            if (indexes[choice_node][0] == -1)
                indexes[choice_node][0] = 0; 
            if (indexes[choice_node][1] == -1)
                indexes[choice_node][1] = 0;
            //cout << "current top element at beginning: " << path.top() 
            //     << " " << indexes[choice_node][0] << " " 
            //     << mask[indexes[choice_node][0]] << '\n'; 
            if (!mask[indexes[choice_node][0]])
                path.emplace(indexes[choice_node][0]);
            else if (!mask[path.top()])
                path.emplace(-1);
            else if (!mask[indexes[choice_node][1]])
                path.emplace(indexes[choice_node][1]);
            else
                path.emplace(-1);
            //cout << "current top element at end: " << path.top() << '\n';
        }
        path.pop();
        //cout << "currently evaluated at the top: " << path.top() << '\n';
        if (!mask[path.top()]) {
            output[i++] = path.top();
            mask[path.top()] = true;
            //cout << "check mask value for " << path.top() << ": " 
            //     << mask[path.top()] << '\n';
        } else if (path.size() > 1)
            path.pop();
    }   
    return output;  
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    // ostream_iterator<int> os(cout, " ");
    // int count{1};
    // for (auto item: indexes) {
    //     cout << "node " << count++ << " children: ";
    //     copy(item.begin(), item.end(), os);
    //     cout << '\n';
    // }
    
    // store tree in a hash table keyed by levels
    int i{1};
    unordered_map<int, vector<int>> levels;
    levels[i].emplace_back(1);
    while (levels[i].size() > 0) {
        for_each(levels[i].begin(), levels[i].end(), 
            [&](int a){
                if (indexes[a-1][0] != -1) 
                    levels[i+1].emplace_back(indexes[a-1][0]);
                if (indexes[a-1][1] != -1) 
                    levels[i+1].emplace_back(indexes[a-1][1]);
            }
        );
        ++i;
    }
    if (levels[i].empty()) // last line always empty erase it
        levels.erase(i);
    // cout << "levels size: " << levels.size() << '\n';
    
    // do the swapping of nodes at queried levels
    vector<vector<int>> result;
    for (int i : queries) {
        for (int j = 1; j*i < levels.size(); ++j) {
            int k = j * i;
            for (int l : levels[k])
                swap(indexes[l-1][0], indexes[l-1][1]);
        }
        result.emplace_back(inOrderTraversal(indexes));
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

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

