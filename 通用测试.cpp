#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;
using std::vector;

void changeone(int &a)
{
	a +=20;
}

int main ()
{
	vector<int> a (10,5);
	vector<int>::iterator iter;
	iter= a.begin();
	changeone(*iter);
	cout<<*iter<<endl;

}
