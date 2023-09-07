#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, Q;
    cin >> N;
    vector<long> input(N);
    for (int i = 0; i != N; ++i)
        cin >> input[i];
    cin >> Q;
    vector<long> queries(Q);
    for (int i = 0; i != Q; ++i)
        cin >> queries[i];
    for (auto& item: queries) {
        auto lower_b = lower_bound(input.begin(), input.end(), item);
        if ((lower_b != input.end()) && (*lower_b == item))
            cout << "Yes " << lower_b - input.begin() + 1 << '\n';
        else
            cout << "No " << lower_b - input.begin() + 1 << '\n';
    }
    
    return 0;
}
