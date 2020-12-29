#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int entryTime(string s, string keypad) {
    int s_size = s.size();
    if (s_size == 1)
        return 0;

    vector<int> s_int(s_size, 0), key_int(9, 0);
    for (int ii = 0; ii != s_size; ++ii)
        s_int[ii] = s[ii] - '0';
    for (int ii = 0; ii != 9; ++ii)
        key_int[ii] = keypad[ii] - '0';

    int counter(0);
    for (int ii = 1; ii != s_size; ++ii) {
        if (s_int[ii-1] == s_int[ii])
            continue;

        int a = s_int[ii-1];
        int b = s_int[ii];
        auto pos_a = find(key_int.begin(), key_int.end(), a);
        auto pos_b = find(key_int.begin(), key_int.end(), b);
        int abs_dist_a = pos_a - key_int.begin();
        int abs_dist_b = pos_b - key_int.begin();
        int row_a = abs_dist_a / 3;
        int row_b = abs_dist_b / 3;
        int col_a = abs_dist_a % 3;
        int col_b = abs_dist_b % 3;
        int row_distance = abs(row_b - row_a);
        if (row_distance == 2)
            counter += 2;
        else if (row_distance == 1) {
            if ((col_a == 1 || col_b == 1) || (col_a == col_b))
                ++counter;
            else if ((col_a == 0 && col_b == 2) ||
                     (col_a == 2 && col_b == 0))
                counter += 2;
        } else if (row_distance == 0) {
            if (abs(col_a - col_b) == 1)
                ++counter;
            else if (abs(col_a - col_b) == 2)
                counter += 2;
        }
    }

    return counter;
}


int main()
{
    string input0 = "45312";
    string input1 = "789456123";
    int sol = entryTime(input0, input1);
    cout << "45312, 789456123 ? 5: " << sol << endl;

    return 0;
}
