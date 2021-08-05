#include <iostream>

using namespace std;

int main()
{#include <cmath>

using namespace std;

class Answer
{
public:
    /// This method finds the number closest to​​​​​​‌​​​‌‌‌‌​​​‌​‌‌​‌‌‌‌​​‌​‌ zero
    static int closestToZero(int ints[], int size) {
        if (size == 0)
            return 0;
        int abs_min = 2147483647;
        for (int* ii = ints; ii != ints + size; ++ii) {
            if (abs(*ii) <= abs_min) {
                if (abs_min == abs(*ii) && *ii > 0)
                    abs_min = *ii;
            }
            cerr << abs_min << " " << endl;
        }
        return abs_min;
	}
};
