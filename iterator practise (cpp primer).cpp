#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void Q317 ()
{
	vector<int> ve;
	vector<int>::iterator ite;		// don't forget vector<int>
	int i;

	//input
	for (int temp;cin>> temp ; )
	{
		ve.push_back(temp);
	}

	//add every two number
	for (ite=ve.begin()+1;ite <ve.end();ite+=2)
	{
		cout<< *ite + *(ite-1) ;
	}
	cout <<endl;

	//check for left over
	if (ite==ve.end())
		cout<< "there is a left over " <<endl ;

}


void Q318 ()
{
	vector<int> a(10,0);
	vector<int>::iterator ite ;
	cout << "please give ten numbers" <<endl;
	for (int i=0; i<10 ; i++)
		cin>> a[i];

	for (ite = a.begin();ite!=a.end();++ite)
		*ite*=2;

	for (ite=a.begin();ite!=a.end();++ite)
		cout<< *ite << " ";

		cout <<endl;

}

int main()
{
	// page 87
//	Q317();
	Q318();
	return 0;
}
