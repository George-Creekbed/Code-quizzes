#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    size_t size_ranked{ranked.size()};
    
    vector<int> position_ranked(size_ranked);
    position_ranked[0] = 1;
    // cout << "ranked: " << endl;
    // cout << position_ranked[0];
    for (int i=1; i!=size_ranked; ++i) {
        position_ranked[i] = position_ranked[i-1];
        if (ranked[i] != ranked[i-1]) {
            ++position_ranked[i];
        }
        // cout << " " << position_ranked[i];
    }
    // cout << endl;
    
    size_t size_player{player.size()};
    vector<int> position_player(size_player);
    for (int i=0; i!=size_player; ++i) {
        // iterator of biggest element in ranked <= to current player score
        auto iter_to_ranked = lower_bound( 
            ranked.begin(), 
            ranked.end(), 
            player[i], 
            greater<int>()
        );
        // turn iterator to array index
        size_t index = distance(ranked.begin(), iter_to_ranked);
        if (index == size_ranked) { // if beyond last
            position_player[i] = *(position_ranked.end()-1) + 1;
        } else {      
            position_player[i] = position_ranked[index];
        }
    }
    
    return position_player;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ranked_count_temp;
    getline(cin, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(cin, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);

    vector<string> player_temp = split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

    vector<int> result = climbingLeaderboard(ranked, player);

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
