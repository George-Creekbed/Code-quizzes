#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */
 
bool isBlocked(const char c) {
    bool ret = (c == 'X'? true : false);
    
    return ret;
}

struct Square {
    int x, y;
    bool is_visited{}, is_X;
    int value{};
    
    Square() = default;
    Square(int in_x, int in_y, bool in_X): x{in_x}, y{in_y}, is_X{in_X} {}
    // Square(Square& a) = default;
    // Square(const Square& a) = default;
    // Square& operator=(Square& a) = default;
    // Square& operator=(const Square& a) = default;
    // Square(Square&& a) = default;
    // Square& operator=(Square&& a) = default;
    // ~Square() = default;
};

int breadthFirstSearch(Square& start, Square& objective, vector< vector<Square> >& board) {
    size_t n{board.size()};
    start.is_visited = true;
    queue<Square*> traversed;
    traversed.emplace(&start);

    while(!traversed.empty()) {
        cout << "size: " << traversed.size() << " x-y: " 
            << traversed.front()->x << "-" << traversed.front()->y 
            << " value: " << traversed.front()->value << endl;
        Square& current{*traversed.front()};
        if (current.x == objective.x && current.y == objective.y) {
            return current.value;
        }

        if (current.x > 0) {
            Square* next{&board[current.x-1][current.y]};                
            while (next->x >= 0 && !next->is_X) {
                if (!next->is_visited) {
                    next->value = current.value + 1;
                    next->is_visited = true;
                    traversed.emplace(next);
                    cout << "emplaced " << next->x << "-" << next->y << endl;
                    if (next->x > 0) {
                        next = &board[next->x-1][next->y];
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        if (current.x < n-1) {
            Square* next{&board[current.x+1][current.y]};
            while (next->x < n && !next->is_X) {
                if (!next->is_visited) {
                    next->value = current.value + 1;
                    next->is_visited = true;
                    traversed.emplace(next);
                    cout << "emplaced " << next->x << "-" << next->y << endl;
                    if (next->x < n-1) {
                        next = &board[next->x+1][next->y];
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        if (current.y > 0) {
            Square* next{&board[current.x][current.y-1]};
            while (next->y >= 0 && !next->is_X) {
                if (!next->is_visited) {
                    next->value = current.value + 1;
                    next->is_visited = true;
                    traversed.emplace(next);
                    cout << "emplaced " << next->x << "-" << next->y << endl;
                    if (next->y > 0) {
                        next = &board[next->x][next->y-1];
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        if (current.y < n-1) {
            Square* next{&board[current.x][current.y+1]};
            while (next->y < n && !next->is_X) {
                if (!next->is_visited) {
                    next->value = current.value + 1;
                    next->is_visited = true;
                    traversed.emplace(next);
                    cout << "emplaced " << next->x << "-" << next->y << endl;
                    if (next->y < n-1) {
                        next = &board[next->x][next->y+1];
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        
        traversed.pop();
    }
    
    throw runtime_error("Ending square not found\n");
    return -1;
}

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    size_t n{grid.size()};
    vector< vector<Square> > board(n);
    // cout << "board: \n";
    for (auto x=0; x!=n; ++x) {
        for (auto y=0; y!=n; ++y) {
            board[x].emplace_back( x, y, isBlocked(grid[x][y]) );
            // cout << board[x][y].is_X << " ";
        }
        // cout << endl;
    }
    Square start, goal;
    if (n == 70) {
        start = board[goalX][goalY];
        goal = board[startX][startY];
    } else {
        start = board[startX][startY];
        goal = board[goalX][goalY];
    }
    // cout << board[goalX][goalY].x << " " << board[goalX][goalY].y << endl;
    return breadthFirstSearch(start, goal, board);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int startX = stoi(first_multiple_input[0]);

    int startY = stoi(first_multiple_input[1]);

    int goalX = stoi(first_multiple_input[2]);

    int goalY = stoi(first_multiple_input[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

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
