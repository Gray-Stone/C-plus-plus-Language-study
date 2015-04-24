#include <iostream>
#include <list>
#include <string>
#include "student\student.cpp"

using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;

/////// add_student /////////

student make_student ()
{
	string _name;

	cout << " please enter the name of the student " <<endl;
	cin >> _name ;
	return student(_name);
}
///////////

int main()
{
	list<student> stu;

	///////////load file //////////////////

	//////////////////////////////////////

	for (;;)
	{
		string a;
		cout<< "add / print or change /" <<endl;
		cin >>a;
		if (a=="add")
		{
			student temp = make_student(); ///// 构造新的学生对象

			//// 在正确的位置插入////
			list<student>::iterator iter = stu.begin() ;
			for (;iter!= stu.end();iter++)
			{
				if (iter->getname()>temp.getname()) break;
			}
			stu.insert(iter,temp);
			////////////////////////

		}

	}

	///////////save file////////////////

	////////////////////////////////////
	return 0;
}
