#include <iostream>
#include <vector>

using namespace std;

int hourglassSum(vector<vector<int> > arr) {
    int ret(INT_MIN);
    for (int i = 0; i != 4; ++i) {
        for (int j = 0; j != 4; ++j) {
            int temp = arr[i][j]   + arr[i][j+1]   + arr[i][j+2] +
                                     arr[i+1][j+1] +
                       arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if (temp > ret)
                ret = temp;
        }
    }

    return ret;
}


int main()
{
    vector<vector<int> > input = {
                                      {1,1,1,0,0,0},
                                      {0,1,0,0,0,0},
                                      {1,1,1,0,0,0},
                                      {0,0,2,4,4,0},
                                      {0,0,0,2,0,0},
                                      {0,0,1,2,4,0}
                                 };
    int sol = hourglassSum(input);
    cout << "{{1,1,1,0,0,0},{0,1,0,0,0,0},{1,1,1,0,0,0},{0,0,2,4,4,0},{0,0,0,2,0,0},{0,0,1,2,4,0}} ? 19: "
         << sol << endl;

    return 0;
}
