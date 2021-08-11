#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student {
public:
    void set_age(int input) {age = input;}
    int get_age() {return age;}
    void set_first_name(string input) {first_name = input;}
    string get_first_name() {return first_name;}
    void set_last_name(string input) {last_name = input;}
    string get_last_name() {return last_name;}
    void set_standard(int input) {standard = input;}
    int get_standard() {return standard;}
    string to_string() {
        stringstream ss;
        ss << age << ',' << first_name << ',' << last_name << ',' << standard;
        string ret(ss.str());
        return ret;
    }
private:
    int age, standard;
    string first_name, last_name;
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}
