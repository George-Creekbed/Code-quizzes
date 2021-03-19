#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// This method finds the number closest to​​​​​​‌​​‌​​​​‌‌‌​‌​‌‌​​​​​‌‌‌​ zero
int closestToZero(int ints[], int size) {
    if (size == 0)
        return 0;
    else if (size == 1)
        return ints[0];

    const int MAX = 2147483647;
    int nearest(MAX);
    bool flag_neg = false;
    int ret;
    for (int i = 0; i != size; i++) {
        flag_neg = false;
        if (ints[i] < 0)
            flag_neg = true;
        nearest = min(nearest, abs(ints[i]));
        if (flag_neg && nearest <= abs(ints[i]))
            ret = nearest;
        else if (flag_neg && nearest > abs(ints[i]))
            ret = ints[i];
        else if (!flag_neg && nearest <= ints[i])
            ret = nearest;
        else if (!flag_neg && nearest > ints[i])
            ret = ints[i];
        cout << ret << endl;
    }
    return ret;
}

int main() {
    int ints[] = {1,-2,5,9,7};
    int sol = closestToZero(ints, 5);
    cout << "Solution is: " << sol << endl;

    return 0;
}
