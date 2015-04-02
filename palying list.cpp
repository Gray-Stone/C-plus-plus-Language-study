#include <iostream>
#include<list>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;


int main ()
{
	list<string> a;
	list<string>::iterator iter;
	string element;

	cout<<"please enter the word"<<endl;
	for (;cin>>element;cout<<"please enter the word"<<endl)
	{

		for (iter= a.begin();iter!=a.end();iter++)
		{
			if( *iter>element)
			{
				break;
			}
		}
		a.insert(iter,element);

		cout<<"list : "<<endl;
		for (iter=a.begin();iter!=a.end();iter++)
		{
			cout<<*iter<<endl;
		}

		cout<<"end of list "<< endl;
	}

}
