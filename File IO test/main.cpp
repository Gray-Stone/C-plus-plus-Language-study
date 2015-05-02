#include <iostream>
#include <string>
#include <list>
#include <fstream>

using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ofstream;
using std::ifstream;


class num
{
	public:
	string name;
	int a,b;


	num(string _name, int _a, int _b): name(_name),a(_a),b(_b){;}


};

int main()
{
	list<num> a;
	string intemp;
	for (;;)
	{

		cout<<" add, print, save" <<endl;
		cin>>intemp;
		if (intemp=="add")
		{
			num temp("non",-1,-1);
			cout<<"name, a, b"<<endl;
			cin>>temp.name>>temp.a>>temp.b;
			a.push_back(temp);
		}
		if (intemp=="print")
		{
			list<num>::iterator iter;
			for(iter=a.begin();iter!=a.end();iter++){cout<<iter->name<<" "<<iter->a<<" "<<iter->b<<" "<<endl;}
		}
		if (intemp=="save")
		{

		}
	}

}
