#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//void whatFlavors(vector<int> cost, int money) {
//    int cost_size = cost.size();
//
//    vector<int> saved_order;
//    for (int ii = 0; ii != cost_size; ++ii) {
//        if (cost[ii] < money && ii < cost_size - 1) {
//            for (int jj = ii + 1; jj != cost_size; ++jj) {
//                if (cost[jj] + cost[ii] == money) {
//                    saved_order.push_back(ii+1);
//                    saved_order.push_back(jj+1);
//                    break;
//                }
//            }
//        }
//        if (saved_order.size() == 2)
//            break;
//    }
//
//    cout << saved_order[0] << " " << saved_order[1] << endl;
//}


void whatFlavors(vector<int> cost, int money)
{
    int cost_size = cost.size();

    unordered_multimap<int,int> saved_order;
    for (int ii = 0; ii != cost_size; ++ii) {
        if (cost[ii] < money)
            saved_order.insert(make_pair(cost[ii], ii + 1));
    }

    int saved_order_size = saved_order.size();
    for (int jj = 0; jj != saved_order_size; ++jj) {
        if (saved_order.count(money - cost[jj]) == 1 &&
            saved_order.find(cost[jj]) != saved_order.find(money - cost[jj])) {
            cout << saved_order.find(cost[jj])->second << " "
                 << saved_order.find(money - cost[jj])->second << endl;
            break;
        } else if (saved_order.count(money - cost[jj]) == 2) {
            auto value_range = saved_order.equal_range(cost[jj]);
            int beg = (*(value_range.first)).second;
            int end = (*(++value_range.first)).second;
            cout << min(beg, end) << " " << max(beg, end)
             << endl;
            break;
        }
    }
}


int main()
{
    vector<int> input0 = {1,4,5,3,2};
    int input1 = 4;
    cout << "{1,4,5,3,2}, 4? 1 4: " << endl;
    whatFlavors(input0, input1);

    input0 = {2,2,4,3};
    input1 = 4;
    cout << "{2,2,4,3}, 4? 1 2: " << endl;
    whatFlavors(input0, input1);

    input0 = {4,3,2,5,7};
    input1 = 8;
    cout << "{4,3,2,5,7}, 8? 2 4: " << endl;
    whatFlavors(input0, input1);

    return 0;
}
