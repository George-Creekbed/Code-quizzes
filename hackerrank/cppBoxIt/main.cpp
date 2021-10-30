#include <iostream>
#include <climits>

using namespace std;
//Implement the class Box
const long long int valueFromLimits = LLONG_MAX;
class Box{
    friend ostream& operator<< (ostream&, Box&);
public:
    Box(): l(0), b(0), h(0) {}
    Box(int length, int breadth, int height)
    : l(length), b(breadth), h(height) {}
    Box(const Box& B): l(B.l), b(B.b), h(B.h) {}

    int getLength() {return l;}
    int getBreadth() {return b;}
    int getHeight() {return h;}
    long long CalculateVolume() {return static_cast<long long>(l) * b * h;}

    bool operator<(const Box& B) {
        if (l < B.l) return true;
        else if (l == B.l && b < B.b) return true;
        else if (l == B.l && b == B.b && h < B.h) return true;

        return false;
    }

private:
    int l, b, h;
};

ostream& operator<< (ostream& out, Box& B) {
    return out << B.l << " " << B.b << " " << B.h;
}


void check2()
{
    cout << valueFromLimits << endl;
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
