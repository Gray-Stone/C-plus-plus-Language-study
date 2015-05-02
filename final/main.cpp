#include <iostream>
#include <list>
#include <string>
#include "student\student.cpp"
#include <limits> // 为了使用numeric_limits

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


/////// 修改学生信息 ////////
void modify_student(student &stu)
{
	string intemp;
	list<course> clist = stu.getallcourse();

	// 选择何种操作
	cout <<" a 		: list of all course"<<endl;
	cout <<" b 		: list of all course with score and commons" <<endl;
	cout <<" add 	: add a course" <<endl;
	cout <<" note	: note n for not change"<<endl;
	if (intemp=="a"){print_all_course_name(clist);}
	if (intemp=="b"){print_all_course(clist);}

	// 插入课程
	if (intemp=="add")
	{
		pair< list<course>::iterator,bool > tpair; //// add_subject 的返回类型
		tpair=stu.add_subject( make_course());	//	插入
		if (tpair.second==false) {cout<<" fail to add course "<<endl;}	// 插入失败
		else  if (tpair.second==true) {cout<<" succedd to add course "<<endl;}	//插入成功
	}

	// 显示或更变note
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
		if (temp0=="add") //// 完成
		{
				student temp = make_student(); ///// 构造新的学生对象
				///// 修改该学生 /////
			for (;;)
			{

				string intemp;	// 输入缓存变量
				cout<< " c for add course, n for changed the note, end to finish " <<endl;
				cin>> intemp;
				cin.ignore( numeric_limits<streamsize>::max(),'\n');	// 不清除输入缓冲中剩余的内容会直接影响到 n 情况下的getline；



				if (intemp=="c")	///// add a course
				{
					pair< list<course>::iterator,bool > tpair; //// add_subject 的返回类型
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
			//// 在正确的位置插入////
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

		///////// 提取单个学生 ///////
		if (temp0=="select")
		{
			for (;;)
			{
				string intemp ; //输入缓存变量
				string _name ;
				list<student>::iterator iter;

				cout<<"pleas enter name" <<endl;
				cin>> _name ;	// 获得学生名称

				// 查找学生
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
