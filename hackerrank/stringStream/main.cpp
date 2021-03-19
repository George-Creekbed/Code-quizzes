#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	stringstream ss(str);
    vector<int> out;
    while(ss) {
        int a;
        ss >> a;
        out.push_back(a);
        if (ss) {
            char ch;
            ss >> ch;
        }
    }

    return out;
}

int main() {
    string str;
    cin >> str;
    //str = "23,4,56";
    vector<int> integers = parseInts(str);
    for(size_t i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
