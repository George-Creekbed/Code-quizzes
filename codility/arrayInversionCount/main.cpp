#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    if (A.empty() || A.size() == 1)
        return 0;

    int A_size = A.size();
    int size_a = A_size / 2;
    int size_b;
    if (A_size % 2 == 0)
        size_b = size_a;
    else
        size_b = size_a + 1;
    vector<int> a(size_a, 0);
    vector<int> b(size_b, 0);
    for (int i = 0; i != size_a; ++i){
        a[i] = A[i];
        b[i] = A[size_a + i];
    }
    if (A_size % 2 != 0)
        b[size_b - 1] = A[A_size - 1];

    int inversions_a = 0, inversions_b = 0;
    if (size_a > 1) {inversions_a = solution(a);}
    if (size_b > 1) {inversions_b = solution(b);}

    int inversions = 0;
    int i = 0, j = 0;
    for (int k = 0; k != A_size; ++k){
        if (i < size_a) {
            if ( (j >= size_b) || (a[i] <= b[j]) ) {
                A[k] = a[i];
                i++;
            } else if (j < size_b) {
                A[k] = b[j];
                j++;
                inversions += size_a - i;
            }
        } else if (j < size_b) {
            A[k] = b[j];
            if (a[size_a - 1] > b[j])
                inversions += 1;
            j++;
        }
    }
    inversions += inversions_a + inversions_b;

    if (inversions > 1000000000)
        inversions = -1;

    return inversions;
}

int main()
{
    vector<int> input = {-1,6,3,4,7,4};
    int sol = solution(input);
    cout << "{-1,6,3,4,7,4} ? 4: " << sol << endl;

    return 0;
}
