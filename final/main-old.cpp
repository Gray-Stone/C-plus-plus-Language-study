#include <iostream>
#include <list>
#include <string>
#include <limits> // Ϊ��ʹ��numeric_limits
#include <fstream>

/////////////#include "student\student.cpp"


#include "main2.cpp"

using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::numeric_limits;
using std::streamsize;
using std::ifstream;
using std::ofstream;
using std::ios;

/////// add_student /////////

student make_student ()
{
	string _name;

	cout << " please enter the name of the student " <<endl;
	cin >> _name ;
    cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream
	return student(_name);
}
///////////

////////// add_time //////////
course::times make_time()
{
	cout <<" enter year, term, block "<<endl;
	course::times time;
	cin>>time.year;
	cin>>time.term;
	cin>> time.block;
    cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream
	return time;
}
/////////////

/////// add_course ///////
course make_course()
{
	// name

	string name;
	cout<< " name of the course"<<endl;
	cin>> name;
    cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream

	////////
	course::times time;
	time=make_time();
	course _course(name,time);
	return _course;
}
//////////////

//////// time print //////////
void time_print (course::times time)
{
	cout<<time.year<< "  Term"<<time.term<< "  Block: " <<time.block<<endl;
}

//////// course print /////////
void course_print (course &cou)
{
	cout << " name :"<< cou.getname() << " course date " ;
	time_print(cou.gettime());
	cout << " midterm"<< cou.getmgrade() << " final" << cou.getfgrade() <<endl;
	cout << " commons :	";
	cout<<cou.getcommons()<<endl;
	cout<<" notes:	";
	cout<<cou.getnote()<<endl;

}

/////// print all course ///////
void print_all_course(list<course> &lis)
{
	list<course>::iterator iter;
	for (iter=lis.begin();iter!=lis.end();iter++){course_print(*iter);}
	cout<<" end of list" <<endl;
}

/////// print all course name ////
void print_all_course_name (list<course> &lis)
{
	list<course>::iterator iter ;
	for (iter=lis.begin();iter!=lis.end();iter++)
	{
		cout<< " name: " << iter->getname() << "  ";
		time_print(iter->gettime());
	}
	cout<<" end of list" <<endl;
}


/////// �޸�ѧ����Ϣ ////////
void modify_student(student &stu)
{
	string intemp;
	list<course> clist = stu.getallcourse();

	for (;;)
	{

		// ѡ����ֲ���
		cout <<" a 		: list of all course"<<endl;
		cout <<" b 		: list of all course with score and commons" <<endl;
		cout <<" add 	: add a course" <<endl;
		cout <<" note	: note n for not change"<<endl;

		cin>>intemp;
        cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream


		if (intemp=="a"){print_all_course_name(clist);}
		else if (intemp=="b"){print_all_course(clist);}

		// ����γ�
		else if (intemp=="add")
		{
			pair< list<course>::iterator,bool > tpair; //// add_subject �ķ�������
			tpair=stu.add_subject( make_course());	//	����
			if (tpair.second==false) {cout<<" fail to add course "<<endl;}	// ����ʧ��
			else  if (tpair.second==true) {cout<<" succedd to add course "<<endl;}	//����ɹ�
		}

		// ��ʾ�����note
		else if (intemp=="note") {cout<<stu.getnote()<<endl;}
		{
			cout <<"new note ( n for not changing ):"<<endl;
			getline(cin, intemp);
			if (intemp !="n"){stu.setnote(intemp);}

		    cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream

		}
		//�����޸�
		if (intemp=="exit") break;
	}
}


int main()
{
	list<student> stu;

	///////////load file //////////////////

	//////////////////////////////////////

	for (;;)
	{
		string temp0;
		cout<< " add / print (print all) / select / save " <<endl;
		cin >>temp0;
	    cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream




		////////// add /////////////
		if (temp0=="add") //// ���
		{
			student temp = make_student(); ///// �����µ�ѧ������
			///// �޸ĸ�ѧ�� /////
			modify_student (temp);

			//// ����ȷ��λ�ò���////
			list<student>::iterator iter = stu.begin() ;
			for (;iter!= stu.end();iter++)
			{
				if (iter->getname()>temp.getname()) break;
			}
			stu.insert(iter,temp);
			////////////////////////
		}

		////////////////////////////// end of add

		///////// print ///////////////
		if (temp0=="print")
		{
			list<student>::iterator iter = stu.begin() ;
			////// print all the names
			for (;iter!=stu.end();iter++)
			{
				// print name
				cout<<iter->getname()<<endl;
            }
        ////    cout<<"type \"select\" for pick single student " <<endl;
		}
		///////////////////////////// end of print

		///////// select -��ȡ����ѧ�� ///////
		if (temp0=="select")
		{
			string intemp ; //���뻺�����
			string _name ;
			list<student>::iterator iter;

			for (;;)
			{

				cout<<"pleas enter student name or exit" <<endl;
				cin>> _name ;	// ���ѧ������

				cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream

				//�˳�//

				if (intemp=="exit") break;

				// ����ѧ��
				for (iter=stu.begin();iter!=stu.end();iter++) {if (iter->getname()==_name) break;}
				if (iter==stu.end())
					{cout<<"didn't find the student"<<endl;break;} // �����ҵ�ѧ����

				cout<< "found";
				cout<<"  " <<iter->getname()<<endl;
				modify_student (*iter);

			}
		}
		///////////////////////////// end of select

		//////////save ///////////
		if (temp0=="save")
		{
			list<student>::iterator iter;
			ofstream nf ("names.t",ios::out); /////////// �����������ֵ��ļ�

			/////////// ��������ѧ�� ///////////
			for (iter=stu.begin();iter!=stu.end();iter++)
			{
				nf<<iter->getname()<<endl;	////�������ļ��ﱣ������
                        //// ����student�ĺ���������������ѧ������Ϣ//

			}
			nf<<"end"<<endl;
			cout << "finish saving"<<endl;
			/////������� ////
		}
		////////end of save ////////////

	}

	///////////save file////////////////

	////////////////////////////////////
	return 0;
}
