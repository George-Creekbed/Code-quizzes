#include <iostream>
#include <string>

using namespace std;

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template<> struct Traits<Color>{
    static string name(int& r) {
        string ret;
        switch(r)
        {
            case 0 : ret = "red";   break;
            case 1 : ret = "green"; break;
            case 2 : ret = "orange";  break;
            default: ret = "unknown";
        }
        return ret;
    }
};

template<> struct Traits<Fruit>{
    static string name(int& r) {
        string ret;
        switch(r)
        {
            case 0 : ret = "apple";   break;
            case 1 : ret = "orange"; break;
            case 2 : ret = "pear";  break;
            default: ret = "unknown";
        }
        return ret;
    }
};


int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
