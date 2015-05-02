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
	cout <<" enter year, term, block "<<endl;
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
	cout<< " name of the course"<<endl;
	cin>> name;

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

	// ѡ����ֲ���
	cout <<" a 		: list of all course"<<endl;
	cout <<" b 		: list of all course with score and commons" <<endl;
	cout <<" add 	: add a course" <<endl;
	cout <<" note	: note n for not change"<<endl;
	if (intemp=="a"){print_all_course_name(clist);}
	if (intemp=="b"){print_all_course(clist);}

	// ����γ�
	if (intemp=="add")
	{
		pair< list<course>::iterator,bool > tpair; //// add_subject �ķ�������
		tpair=stu.add_subject( make_course());	//	����
		if (tpair.second==false) {cout<<" fail to add course "<<endl;}	// ����ʧ��
		else  if (tpair.second==true) {cout<<" succedd to add course "<<endl;}	//����ɹ�
	}

	// ��ʾ�����note
	if (intemp=="note") {cout<<stu.getnote()<<endl;}
	{
		cout <<"new note:"<<endl;
		getline(cin, intemp);
		if (intemp !="n"){stu.setnote(intemp);}
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
		cout<< " add / printall students /" <<endl;
		cin >>temp0;

		////////// add /////////////
		if (temp0=="add") //// ���
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
					else  if (tpair.second==true) {cout<<" succedd to add course "<<endl;}
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
				cout<<"select for pick single student " <<endl;
			}
		}
		/////////////////////////////

		///////// ��ȡ����ѧ�� ///////
		if (temp0=="select")
		{
			for (;;)
			{
				string intemp ; //���뻺�����
				string _name ;
				list<student>::iterator iter;

				cout<<"pleas enter name" <<endl;
				cin>> _name ;	// ���ѧ������

				// ����ѧ��
				for (iter=stu.begin();iter!=stu.end();iter++) {if (iter->getname()==_name) break;}
				if (iter==stu.end()) {cout<<"didn't find the student"<<endl;break;}
				cout<< "found";
				cout<<"  " <<iter->getname()<<endl;
				modify_student (*iter);

			}
		}
		/////////////////////////////

	}

	///////////save file////////////////

	////////////////////////////////////
	return 0;
}
