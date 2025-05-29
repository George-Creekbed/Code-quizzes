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
    char letter{'.'};
    int timer{};
    bool spread_bomb{};
    bool next_to_explode{};
    
    void incrementTimer(){
        if (is_bomb) {
            timer++;
            if (timer % 3 == 0) { // explosion
                is_bomb = false;
                next_to_explode = false;
                letter = '.';
                spread_bomb = true;
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
        spread_bomb = false;
    }
};

vector<string> saveGrid(const vector< vector<Cell> >& cells) {
    size_t rows{cells.size()}, cols{cells[0].size()};
    vector<string> grid(rows, string(cols, '.'));
    for (auto i=0; i!=rows; ++i) {
        for (auto j=0; j!=cols; ++j) {
            if (cells[i][j].letter=='O')
                grid[i][j] = 'O';
        }
    }
    
    return grid;
}

vector<string> bomberMan(int n, vector<string> grid) {
    
    size_t rows{grid.size()}, cols{grid[0].size()};
    vector< vector<Cell> > cells(rows, vector<Cell>(cols));
    
    // cout << "initial grid: " << endl;
    for (auto i=0; i!=rows; ++i) {
        for (auto j=0; j!=cols; ++j) {
            if (grid[i][j]=='O' && !cells[i][j].is_bomb) {
                cells[i][j].setBomb();
            }
        }
    }
    
    int t{1};
    vector<string> grid_3(rows), grid_5(rows), grid_even(rows);
    vector<string> current_grid(rows, string(cols, '.'));
    while (t <= n && t < 6) {       
        for (auto i=0; i!=rows; ++i) {
            for (auto j=0; j!=cols; ++j) {
                cells[i][j].incrementTimer();
                if (cells[i][j].spread_bomb) {
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
            grid_even = saveGrid(cells);
            current_grid = grid_even;
        } else if (t == 3) {
            grid_3 = saveGrid(cells);
            current_grid = grid_3;
        } else if (t == 5) {
            grid_5 = saveGrid(cells);
            current_grid = grid_5;
        } 
        
        // // debug 
        // cout << "grid at time " << t << ":" << endl;
        // for (auto i=0; i!=rows; ++i) {
        //     for (auto j=0; j!=cols; ++j) {
        //         cout << current_grid[i][j];
        //     }
        //     cout << endl;
        // }
        // cout << endl;
                
        ++t;
    }
    if (n == 1)
        current_grid = grid;
    else if (n % 4 == 3)
        current_grid = grid_3;
    else if (n % 4 == 1)
        current_grid = grid_5;
    else
        current_grid = grid_even;
    
    return current_grid;
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