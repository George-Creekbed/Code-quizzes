#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
double stringToDouble(string& in)
{
    string::size_type i = 0;
    while ( i != in.size() ) {
        if (in[i] == ',')
            in[i] = '.';
        i++;
    }

    return stod(in);
}

vector<string> split(const string& s)
{
    vector<string> ret;

    typedef string::size_type string_size;
    string_size i = 0;
    while ( i < s.size() ) {
        while ( i != s.size() && isspace(s[i]) ) // == ';' )//( ispunct(s[i]) ) )
            ++i;

        string_size j = i;
        // invariant: none of the characters in range [original j, current j) is a space //or a comma
        while ( j != s.size() && s[j] != ';' ) // ispunct finds all punctuations, included commas
            j++;

        // if we found some nonwhitespace characters
        if (i != j) {
            string word;
            for (string_size index = i; index != j; ++index) {
                string aux(1, s[index]);
                word += aux;
            }

            ret.push_back(word);
            i = j;
        }

        if (i + 1 != s.size() && s[i] == ';' && s[i + 1] == ';') {
            ret.push_back(" ");
            i++;
        } else
            ++i;
    }

    return ret;
}

int main()
{
    ifstream is("input.txt");
    string LON;
    is >> LON; is.ignore();
    string LAT;
    is >> LAT; is.ignore();
    double lon_user = stringToDouble(LON);
    double lat_user = stringToDouble(LAT);
    int N;
    is >> N; is.ignore();
    vector<string> defibr;
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(is, DEFIB);
        defibr.push_back(DEFIB);
    }
    map<double, string> distance_name;
    double min_distance = 1E6;
    for (int i = 0; i < N; i++) {
        vector<string> aux = split(defibr[i]);
        cerr << "aux[0]: " << aux[0] << " aux[1]: " << aux[1] << " aux[2]: " << aux[2]
             << " aux[3]: " << aux[3] << " aux[4]: " << aux[4] << " aux[5]: " << aux[5] << endl;
        double lon_defibr = stringToDouble(aux[4]);
        double lat_defibr = stringToDouble(aux[5]);
        double x = (lon_defibr - lon_user) * cos((lat_defibr + lat_user) / 2.0);
        double y = lat_defibr - lat_user;
        double dist = sqrt(pow(x, 2) + pow(y, 2)) * 6371.0;
        distance_name[dist] = aux[1];
        min_distance = min(min_distance, dist);
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << distance_name[min_distance] << endl;
}
