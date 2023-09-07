#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map<string, int> mymap;
    int Q, type, Y;
    string X;
    cin >> Q;
    for (int i = 0; i != Q; ++i) {
        cin >> type >> X;
        switch (type) {
            case 1:
                cin >> Y;
                if (mymap.count(X) == 1)
                    mymap[X] += Y;
                else
                    mymap.emplace(make_pair(X, Y));
                break;
            case 2:
                mymap.erase(X);
                break;
            case 3:
                cout << mymap[X] << '\n';
                continue;
        }
    }
    return 0;
}
