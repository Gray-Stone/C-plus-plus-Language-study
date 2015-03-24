
#include <string>
#include <vector>
#include<fstream>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ifstream;
using std::ofstream;

int main ()
{
	ifstream inf ;
	ofstream  outf ;
	fstream f;
	vector<string> a;
	unsigned int i ;

    f.open("test.txt");
    for ( ;!f.eof();)
	{	string temp ;
		f>> temp ;
		a.push_back(temp);
	}
	f.close();


	f.open("textcopy.txt");
	for ( i=0;i<a.size();i++)
	{
		f<< a[i] <<endl;
	}
	f.close();

}
