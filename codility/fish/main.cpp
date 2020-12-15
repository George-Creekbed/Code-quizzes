#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    list<int> fish;
    stack<int> upstream;
    for (int ii = A.size() - 1; ii >= 0; --ii) {
        if (B[ii] == 0)
            upstream.push(A[ii]);
        else {
            fish.push_back(A[ii]);
            while ( !upstream.empty() ) {
                if ( upstream.top() > fish.back() ) {
                    fish.pop_back();
                    fish.push_back( upstream.top() );
                    upstream.pop();
                    --ii;
                    if (ii < 0) {
                        ++ii;
                        break;
                    } else {
                        while (!fish.empty() && ii < (int) B.size()) {
                            if (B[ii] == 0) {
                                upstream.push(fish.back());
                                fish.pop_back();
                                ++ii;
                                break;
                            }
                            if ( fish.back() > A[ii] )
                                --ii;
                            else {
                                ++ii;
                                fish.pop_back();
                                //upstream.pop();
                                break;
                            }
                        }
                        break;
                    }
                } else
                    upstream.pop();
            }
        }
    }

    int add_size = 0;
    if ( !upstream.empty() )
        add_size = upstream.size();

    return fish.size() + add_size;
}

int main()
{
    vector<int> input0 = {4,3,2,1,5};
    vector<int> input1 = {0,1,0,0,0};
    int sol = solution(input0, input1);
    cout << "{[4,3,2,1,5], [0,1,0,0,0]} ? 2: " << sol << endl;

    return 0;
}
