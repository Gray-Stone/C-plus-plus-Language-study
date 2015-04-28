#include <iostream>
#include <list>
#include <string>
#include "student\student.cpp"
#include <limits> // Ϊ��ʹ��numeric_limits

using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::numeric_limits;
using std::streamsize;

/////// add_student /////////

student make_student ()
{
	string _name;

	cout << " please enter the name of the student " <<endl;
	cin >> _name ;
	return student(_name);
}
///////////

////////// add_time //////////
course::times make_time()
{
	cout <<"enter year, term, block "<<endl;
	course::times time;
	cin>>time.year;
	cin>>time.term;
	cin>> time.block;
	cin.ignore( numeric_limits<streamsize>::max(),'\n');
	return time;
}
/////////////

/////// add_course ///////
course make_course()
{
	// name

	string name;
	cout<< "name of the course"<<endl;
	cin>> name;

	////////
	course::times time;
	time=make_time();
	course _course(name,time);
	return _course;
}
//////////////




int main()
{
	list<student> stu;

	///////////load file //////////////////

	//////////////////////////////////////

	for (;;)
	{
		string temp0;
		cout<< "add / print or change /" <<endl;
		cin >>temp0;

		////////// add /////////////
		if (temp0=="add")
		{
				student temp = make_student(); ///// �����µ�ѧ������
				///// �޸ĸ�ѧ�� /////
			for (;;)
			{

				string intemp;	// ���뻺�����
				cout<< " c for add course, n for changed the note, end to finish " <<endl;
				cin>> intemp;
				cin.ignore( numeric_limits<streamsize>::max(),'\n');	// ��������뻺����ʣ������ݻ�ֱ��Ӱ�쵽 n ����µ�getline��



				if (intemp=="c")	///// add a course
				{
					pair< list<course>::iterator,bool > tpair; //// add_subject �ķ�������
					tpair=temp.add_subject( make_course());
					if (tpair.second==false) {cout<<" fail to add course "<<endl;}
					else  if (tpair.second==true) {cout<<"succedd to add course "<<endl;}
				}

				if (intemp=="n")	/////change note
				{
                    cout<< "current note :" ;
                    string _note=temp.getnote();
                    cout<< _note <<endl;
                    cout<<"n for not change " <<endl;
                    getline(cin,_note);
                    if (_note!="n"){temp.setnote(_note);}
				}

				if (intemp=="end") break; ///// finish

				//////////////////////
			}
			//// ����ȷ��λ�ò���////
			list<student>::iterator iter = stu.begin() ;
			for (;iter!= stu.end();iter++)
			{
				if (iter->getname()>temp.getname()) break;
			}
			stu.insert(iter,temp);
			////////////////////////
		}

		//////////////////////////////


		///////// print ///////////////
		if (temp0=="print")
		{
			list<student>::iterator iter = stu.begin() ;
			for (;iter!=stu.end();iter++)
			{
				// print name
				cout<<iter->getname()<<endl;

			}
		}
		/////////////////////////////

	}

	///////////save file////////////////

	////////////////////////////////////
	return 0;
}
