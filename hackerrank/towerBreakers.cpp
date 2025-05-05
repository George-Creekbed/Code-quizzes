#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'towerBreakers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

int towerBreakers(int n, int m) {
    if (m == 1)
        return 2;
    else if (n % 2 == 0)
        return 2;
    else 
        return 1;
}
    //int counter(0), ret(1);
    //vector<int> towers(n, m);
    //while (*max_element(towers.begin(), towers.end()) > 1) {
        //++counter;
        //ret = counter % 2 == 1? 1 : 2;
        //sort(towers.begin(), towers.end());
        //if (n == 1)
            //towers[n-1] = 1;
        //else { 
            //if (towers[n-2] == 1) {
                //if ((n % 2 == 1 && ret == 1) || (n % 2 == 0 && ret == 2))
                    //towers[n-1] = 1;
            //} else 
                //for (int i= towers[n-1]/2; i != 0; --i)
                    //if (towers[n-1] % i == 0) {
                        //towers[n-1] = i;
                        //break;
                    //}
        //}
    //}
    
    //return ret;
//}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = towerBreakers(n, m);

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
