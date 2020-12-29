#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countSwaps(vector<int> a)
{
    int n = a.size();

    int num_swaps(0);
    // Bubblesort
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                num_swaps++;
            }
        }
    }

    int first_element = a[0];
    int last_element = *(a.end() - 1);
    cout << "Array is sorted in " << num_swaps << " swaps." << endl;
    cout << "First Element: " << first_element << endl;
    cout << "Last Element: " << last_element << endl;
}

int main()
{
    vector<int> a = {6,4,1};
    countSwaps(a);
    cout << "3, 1, 6" << endl << endl;

    a = {1,2,3};
    countSwaps(a);
    cout << "0, 1, 3" << endl << endl;

    a = {3,2,1};
    countSwaps(a);
    cout << "3, 1, 3" << endl << endl;

    return 0;
}
