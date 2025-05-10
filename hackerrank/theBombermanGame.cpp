// solution obtained with POD structure 
// graded 40% only:
// correct results but too slow
// too many Cell structures created and to update 
// at each iteration

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */
struct Cell {
    bool is_bomb{}; // 0=no bomb; 1=bomb set, start timer
    char letter{'.'}; // '.'=no bomb, 'O'=with bomb
    int timer{};
    bool spread_explosion{};
    bool next_to_explode{}; // 1s left for bomb in this cell to explode
    
    void incrementTimer(){
        if (is_bomb) {
            timer++;
            if (timer % 3 == 0) { // explosion
                is_bomb = false;
                next_to_explode = false;
                letter = '.';
                spread_explosion = true;
                timer = 0;
            } else if (timer % 3 == 2) {
                next_to_explode = true;
            }
        }
    }
    
    void setBomb(){
        is_bomb = true;
        letter = 'O';
    } 
    
    void emptyBomb(){
        if (!next_to_explode) {
            is_bomb = false;
            letter = '.';
            timer = 0;
        }
    } 
    
    void afterExplosion(){
        spread_explosion = false;
    }
};

vector<string> bomberMan(int n, vector<string> grid) {
    size_t rows{grid.size()}, cols{grid[0].size()};
    vector< vector<Cell> > cells(rows, vector<Cell>(cols));
    
    cout << "initial grid: " << endl; // debug
    for (auto i=0; i!=rows; ++i) {
        for (auto j=0; j!=cols; ++j) {
            if (grid[i][j]=='O' && !cells[i][j].is_bomb) {
                cells[i][j].setBomb();
            }
            cout << cells[i][j].letter; // debug
        }
        cout << endl; // debug
    }
    cout << endl; // debug
    
    int t{1};
    while (t <= n) {        
        for (auto i=0; i!=rows; ++i) {
            for (auto j=0; j!=cols; ++j) {
                cells[i][j].incrementTimer();
                if (cells[i][j].spread_explosion) {
                    if (i!=0)
                        cells[i-1][j].emptyBomb();
                    if (i!=rows-1)
                        cells[i+1][j].emptyBomb();
                    if (j!=0)
                        cells[i][j-1].emptyBomb();
                    if (j!=cols-1) {
                        cells[i][j+1].emptyBomb();
                    }
                        
                    cells[i][j].afterExplosion();
                }
            }
        }
        
        if (t%2 == 0) {
            for (auto i=0; i!=rows; ++i) {
                for (auto j=0; j!=cols; ++j) {
                    if (cells[i][j].is_bomb == false) {
                        cells[i][j].setBomb();
                    }
                }
            }
        }
        
        // debug
        cout << "grid at time " << t << ":" << endl;
        for (auto i=0; i!=rows; ++i) {
            for (auto j=0; j!=cols; ++j) {
                cout << cells[i][j].letter;
            }
            cout << endl;
        }
        cout << endl;
        //
        
        ++t;
    }
    
    cout << "final grid: " << endl;  // debug
    for (auto i=0; i!=rows; ++i) {
        for (auto j=0; j!=cols; ++j) {
            if (cells[i][j].letter=='O')
                grid[i][j] = 'O';
            else
                grid[i][j] = '.';
            cout << grid[i][j];  // debug
        }
        cout << endl;  // debug
    }
    
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

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
