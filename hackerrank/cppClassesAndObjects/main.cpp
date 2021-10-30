#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cassert>

using namespace std;

// Write your Student class here
const int number_exams(5);

struct Student {
    int scores[number_exams];

    void input() {
        for (auto& i: scores)
            cin >> i;
    }

    int calculateTotalScore() {
        return accumulate(scores, scores + number_exams, 0);
    }
};

/* SAMPLE INPUT:    // check how many students outperform (higher
                    // sum of scores) the control student
    3               // total students
    30 40 45 10 10  // control student
    40 40 40 10 10
    50 20 30 10 10
    OUTPUT: 1
*/
int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}
