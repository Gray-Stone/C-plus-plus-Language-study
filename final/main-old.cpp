#include <iostream>
#include <list>
#include <string>
#include <limits> // 为了使用numeric_limits
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


/////// 修改学生信息 ////////
void modify_student(student &stu)
{
	string intemp;
	list<course> clist = stu.getallcourse();

	for (;;)
	{

		// 选择何种操作
		cout <<" a 		: list of all course"<<endl;
		cout <<" b 		: list of all course with score and commons" <<endl;
		cout <<" add 	: add a course" <<endl;
		cout <<" note	: note n for not change"<<endl;

		cin>>intemp;
        cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream


		if (intemp=="a"){print_all_course_name(clist);}
		else if (intemp=="b"){print_all_course(clist);}

		// 插入课程
		else if (intemp=="add")
		{
			pair< list<course>::iterator,bool > tpair; //// add_subject 的返回类型
			tpair=stu.add_subject( make_course());	//	插入
			if (tpair.second==false) {cout<<" fail to add course "<<endl;}	// 插入失败
			else  if (tpair.second==true) {cout<<" succedd to add course "<<endl;}	//插入成功
		}

		// 显示或更变note
		else if (intemp=="note") {cout<<stu.getnote()<<endl;}
		{
			cout <<"new note ( n for not changing ):"<<endl;
			getline(cin, intemp);
			if (intemp !="n"){stu.setnote(intemp);}

		    cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream

		}
		//结束修改
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
		if (temp0=="add") //// 完成
		{
			student temp = make_student(); ///// 构造新的学生对象
			///// 修改该学生 /////
			modify_student (temp);

			//// 在正确的位置插入////
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

		///////// select -提取单个学生 ///////
		if (temp0=="select")
		{
			string intemp ; //输入缓存变量
			string _name ;
			list<student>::iterator iter;

			for (;;)
			{

				cout<<"pleas enter student name or exit" <<endl;
				cin>> _name ;	// 获得学生名称

				cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream

				//退出//

				if (intemp=="exit") break;

				// 查找学生
				for (iter=stu.begin();iter!=stu.end();iter++) {if (iter->getname()==_name) break;}
				if (iter==stu.end())
					{cout<<"didn't find the student"<<endl;break;} // 买有找到学生。

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
			ofstream nf ("names.t",ios::out); /////////// 保存所有名字的文件

			/////////// 保存所有学生 ///////////
			for (iter=stu.begin();iter!=stu.end();iter++)
			{
				nf<<iter->getname()<<endl;	////在索引文件里保存名字
                        //// 调用student的函数，保存这个这个学生的信息//

			}
			nf<<"end"<<endl;
			cout << "finish saving"<<endl;
			/////保存完毕 ////
		}
		////////end of save ////////////

	}

	///////////save file////////////////

	////////////////////////////////////
	return 0;
}
