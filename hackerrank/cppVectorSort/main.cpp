#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    ifstream inp("input.txt", fstream::in);
    //cin >> n;
    inp >> n;

    vector<int> my_vec(n);
    for (int i = 0; i != n; ++i) {
        //cin >> my_vec[i];
        inp >> my_vec[i];
    }
    sort(my_vec.begin(), my_vec.end());
    copy(my_vec.begin(), my_vec.end(), ostream_iterator<int>(cout, " "));

    inp.close();

    return 0;
}
