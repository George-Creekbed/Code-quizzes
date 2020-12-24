#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// a greedy solution to the selectStock task problem
int selectStockGreedy(int saving, vector<int> currentValue, vector<int> futureValue) {
    int size = currentValue.size();

    // create a vector<pair<int, int> > that links profit of profitable stocks to their initial position
    vector<pair<int, int> > profit_to_index;
    for (int ii = 0; ii != size; ++ii) {
        int is_profitable = max(0, futureValue[ii] - currentValue[ii]);
        if (is_profitable > 0) {
            pair<int,int> aux(is_profitable, ii);
            profit_to_index.push_back(aux);
        }
    }
    // sorting increases accuracy of the greedy algorithm
    sort(profit_to_index.begin(), profit_to_index.end(),
        [&](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first > b.first;
        });

    int ret(0);
    size_t ii(0);
    // greedy solution, keep adding profitable stocks to return value while saving >= 0
    while ( ii != profit_to_index.size() ) {
        ret += profit_to_index[ii].first;
        saving -= currentValue[profit_to_index[ii].second];
        if (saving < 0) {   // backtrack if saving is negative, try with next stock
            ret -= profit_to_index[ii].first;
            saving += currentValue[profit_to_index[ii].second];
        }
        ++ii;
    }

    return ret;
}

// a dynamic programming solution to the selectStock problem
int selectStock(int saving, vector<int> currentValue, vector<int> futureValue) {
    int input_size = currentValue.size();

    // store profitable stocks and their current costs in two separate vectors
    vector<int> profit, used_currentValue;
    for (int ii = 0; ii != input_size; ++ii) {
        int aux = futureValue[ii] - currentValue[ii];
        if (aux > 0 && currentValue[ii] <= saving) {
            profit.push_back(aux);
            used_currentValue.push_back(currentValue[ii]);
        }
    }
    if ( profit.empty() )
        return 0;

    // create matrix to store dynamic programming sub-solutions
    vector<vector<int> > dp;
    // first row is made of the single profitable stocks
    dp.push_back(profit);
    // similar matrix, keep track of costs of selected stocks in dp
    vector<vector<int> > stocks_bought;
    stocks_bought.push_back(used_currentValue);
    // initialise return value as maximum profit among single stocks
    int ret( *max_element(profit.begin(), profit.end()) );

    int profit_length = profit.size();
    // outer loop populates rows of dp
    for (int ii = 1; ii != profit_length; ++ii) {
        int length_previous_row = dp[ii-1].size();
        vector<int> aux, aux_stocks_bought;

        // 1st nested loop selects column in dp
        for (int jj = 0; jj < length_previous_row - ii; ++jj) {
            int add_this_to_kk = jj / (profit_length - ii);
            int and_this_too = jj % (profit_length - ii + 1);

            // 2nd nested loop adds each of the profitable stocks to each value of the previous row in dp
            for (int kk = ii + add_this_to_kk + and_this_too; kk < profit_length; ++kk) {
                aux.push_back(dp[ii-1][jj] + profit[kk]);
                aux_stocks_bought.push_back(stocks_bought[ii-1][jj] + used_currentValue[kk]);
                // if best value so far within saving constraints, store it as return value
                if (aux_stocks_bought.back() <= saving && aux.back() > ret)
                    ret = aux.back();
            }
        }
        dp.push_back(aux);
        stocks_bought.push_back(aux_stocks_bought);
    }

    return ret;
}

int main()
{
    int input0 = 12;
    vector<int> input1 = {1,3,3,4};
    vector<int> input2 = {3,7,4,9};
    int sol = selectStock(input0, input1, input2);
    int sol_greedy = selectStockGreedy(input0, input1, input2);
    cout << "12, {1,3,3,4}, {3,7,4,9} ? ans: 12.                 Greedy solution :  " << sol_greedy
         << "; dynamic solution : " << sol << endl;

    input0 = 2;
    input1 = {};
    input2 = {};
    sol = selectStock(input0, input1, input2);
    sol_greedy = selectStockGreedy(input0, input1, input2);
    cout << "2, {}, {} ? ans: 0.                                 Greedy solution :  " << sol_greedy
         << ";  dynamic solution : " << sol << endl;

    input0 = 2;
    input1 = {1,3};
    input2 = {0,2};
    sol = selectStock(input0, input1, input2);
    sol_greedy = selectStockGreedy(input0, input1, input2);
    cout << "2, {1,3}, {0,2} ? ans: 0.                           Greedy solution :  " << sol_greedy
         << ";  dynamic solution : " << sol << endl;

    input0 = 5;
    input1 = {6,3};
    input2 = {10,2};
    sol = selectStock(input0, input1, input2);
    sol_greedy = selectStockGreedy(input0, input1, input2);
    cout << "5, {6,3}, {10,2} ? ans: 0.                          Greedy solution :  " << sol_greedy
         << ";  dynamic solution : " << sol << endl;

    input0 = 5;
    input1 = {4,3};
    input2 = {10,4};
    sol = selectStock(input0, input1, input2);
    sol_greedy = selectStockGreedy(input0, input1, input2);
    cout << "5, {4,3}, {10,4} ? ans: 6.                          Greedy solution :  " << sol_greedy
         << ";  dynamic solution : " << sol << endl;

    input0 = 15;
    input1 = {4,3,9,7,12,1,5};
    input2 = {10,7,12,7,14,3,10};
    sol = selectStock(input0, input1, input2);
    sol_greedy = selectStockGreedy(input0, input1, input2);
    cout << "15, {4,3,9,7,12,1,5}, {10,7,12,7,14,3,10} ? ans: 17.Greedy solution :  " << sol_greedy
         << "; dynamic solution : " << sol << endl;

    input0 = 7;
    input1 = {4,3,9,7,12,1,5};
    input2 = {10,7,12,7,14,3,10};
    sol = selectStock(input0, input1, input2);
    sol_greedy = selectStockGreedy(input0, input1, input2);
    cout << "7, {4,3,9,7,12,1,5}, {10,7,12,7,14,3,10} ? ans: 10. Greedy solution :  " << sol_greedy
         << "; dynamic solution : " << sol << endl;

    input0 = 15;
    input1 = {4,3,9,7,12,1,5};
    input2 = {3,3,6,8,8,1,2};
    sol = selectStock(input0, input1, input2);
    sol_greedy = selectStockGreedy(input0, input1, input2);
    cout << "15, {4,3,9,7,12,1,5}, {3,3,6,8,8,1,2} ? ans: 1.     Greedy solution :  " << sol_greedy
         << ";  dynamic solution : " << sol << endl;

    input0 = 15;
    input1 = {4,3,9,7,12,1,5};
    input2 = {3,3,6,6,8,1,2};
    sol = selectStock(input0, input1, input2);
    sol_greedy = selectStockGreedy(input0, input1, input2);
    cout << "15, {4,3,9,7,12,1,5}, {3,3,6,6,8,1,2} ? ans: 0.     Greedy solution :  " << sol_greedy
         << ";  dynamic solution : " << sol << endl;

    return 0;
}
