#include <iostream>
#include <string>
#include <vector>
#include<fstream>
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

int main ()
{
	ifstream inf ;
	ofstream  outf ;
	vector<string> a;
	unsigned int i ;

    inf.open("test.txt");
    for ( ;!inf.eof();)
	{	string temp ;
		inf>> temp ;
		a.push_back(temp);
	}
	cout << a[0];

}
