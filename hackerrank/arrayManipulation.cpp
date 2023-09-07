#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

// brute force
//long arrayManipulation(int n, vector<vector<int>> queries) {
    //vector<vector<long>> aux(queries.size()+1);
    //aux[0] = vector<long>(n, 0);
    //copy(aux[0].begin(), aux[0].end(), ostream_iterator<long>(cout, " "));
    //cout << '\n';
    //long maxx{0};
    //for (size_t i = 1; i != aux.size(); ++i) {
        //aux[i] = vector<long>(aux[i-1]);
        //for (size_t j = 0; j != aux[i].size(); ++j) {
            //if ((j >= queries[i-1][0]-1) && (j <= queries[i-1][1]-1))
                //aux[i][j] += queries[i-1][2]; 
            //maxx = max(maxx, *max_element(aux[i].begin(), aux[i].end())); 
        //}
        //copy(aux[i].begin(), aux[i].end(), ostream_iterator<long>(cout, " "));
        //cout << '\n';        
    //} 
    
    //return maxx;
}

// with ordered map
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<vector<long>> aux(queries.size()+1);
    map<int, long> mymap;
    for (auto& i: queries) {
        mymap[i[0]] += i[2];
        mymap[i[1]+1] -= i[2];
    }
    long mysum{0}, maxx{0};
    for (auto& i: mymap) {
        mysum += i.second;
        maxx = max(maxx, mysum);
    }
    
    return maxx;
	//for_each(aux[i].begin()+queries[i-1][0]-1, aux[i].begin()+queries[i-1][1],                           
	//    [&](long& a){
	//        a += queries[i-1][2];
	//        maxx = max(maxx, a);
	//    }
	//);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    long result = arrayManipulation(n, queries);

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
