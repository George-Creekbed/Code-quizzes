#include <array>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int counter_prof = 1;
int counter_stud = 1;

class Person {
public:
    Person(): name(), age(0) {}
    virtual ~Person() {};
    virtual void getdata(istream& in) = 0;
    virtual void putdata() = 0;
protected:
    string name;
    int age;
};

class Professor: public Person {
public:
    Professor(): Person(), publications(0), cur_id(counter_prof++) {}
    virtual ~Professor() {};
    virtual void getdata(istream& in) override {
        in >> name >> age >> publications;
    }

    virtual void putdata() override {
        cout << name << " " << age << " "
             << publications << " " << cur_id << endl;
    }
private:
    int publications;
    int cur_id;
};

struct write_on_int {
    void operator()(int& a) {
        cin >> a;
    }
};

class Student: public Person {
public:
    Student(): Person(), marks(), cur_id(counter_stud++) {}
    virtual ~Student() {};
    void getdata(istream& in) override {
        in >> name >> age;
        for_each(marks.begin(), marks.end(), [&in](int& a) {in >> a;}); // write_on_int());
    }

    void putdata() override {
        cout << name << " " << age << " "
             << accumulate(marks.begin(), marks.end(), 0)
             << " " << cur_id << endl;
    }
private:
    array<int, 6> marks;
    int cur_id;
};


int main(){

    int n, val;
    //cin>>n; //The number of objects that is going to be created.
    ifstream inp("input.txt", fstream::in);
    inp >> n;
    Person *per[n];

    for(int i = 0;i < n;i++){
        //cin>>val;
        inp >> val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(inp); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    inp.close();

    return 0;

}
