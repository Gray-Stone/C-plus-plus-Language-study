#include <iostream>
#include <list>
#include <string>
#include <limits> // 为了使用numeric_limits
#include <fstream>

#include <direct.h> // 创造文件夹

#include "student\student.cpp"

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

void modify_student(student &stu);
void time_print (course::times time);
course make_course();
course::times make_time();



int main()
{

    list<student> stu;

    for(;;)
    {
        ////// select function //////
        string intemp;
        cout<< " modify / print (print all) / save " <<endl;
        cin>>intemp;
        cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream

            if (intemp== "modify")
            {
                list<student>::iterator iter;
                string _name;
                cout<< "please enter student name (add for adding a new student)"<<endl;
                cin>>_name;
                cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream

                ////// adding student //////
                    if (_name=="add")
                    {
                        cout<< "please enter the name of the student" <<endl;
                        cin>>_name;
                        cout<< "please enter student name (add for adding a new student)"<<endl;
                        student _student(_name); ////// 构造新的学生对象
                        stu.push_back(_student);
                        modify_student(_student);
                        cout<<"end of a_modify"<<endl;
                        stu.push_back(_student);

                    }
                    else
                    {

                        ////// search for the student //////
                        for (iter=stu.begin();iter!=stu.end();iter++)
                            {if (iter->getname()==_name) break;}
                        if (iter==stu.end())
                            {cout<<"didn't find the student"<<endl;} // 买有找到学生。
                        else
                        {

                        cout<< "found";
                        cout<<"  " <<iter->getname()<<endl;
                        modify_student (*iter);
                        }
                    }

            }



            //////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////


            if (intemp=="print")
            {

            }

            //////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////

            if (intemp=="save")
            {
                list<student>::iterator iter;
                ofstream nf ("names.t",ios::out); /////////// 保存所有名字的文件

                nf<<"start"<<endl; ///// 标记保存起点
                /////////// 保存所有学生 ///////////
                for (iter=stu.begin();iter!=stu.end();iter++)
                {
                    nf<< iter->getname() <<endl;	////在索引文件里保存名字

                     _mkdir( (iter->getname()).c_str());///////// 创建文件夹
                       iter->save();     //// 调用student的函数，保存这个这个学生的信息//
                }
                nf<<"end"<<endl;
                cout << "finish saving"<<endl;
                nf.close();
                /////保存完毕 ////

            }

            if (intemp=="exit")
                break;

    }//// end of big for

}//// end of main2






void modify_student(student &stu)
{

    for(;;)
    {
        string intemp;
        cout <<" list 	: list of all course"<<endl;
        cout <<" list2	: list of all course with score and commons" <<endl;
        cout <<" add 	: add a course" <<endl;
        cout <<" note	: change notes"<<endl;
        cin>>intemp;
        cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream

        if(intemp=="list")
        {
            list<course> clist;
            clist=stu.getallcourse();
            list<course>::iterator iter;

            for(iter=clist.begin();iter!=clist.end();iter++)
            {
               cout<< iter->getname()<<endl;
            }
        }


        else if (intemp=="list2")
        {
            list<course> clist;
            clist=stu.getallcourse();
            list<course>::iterator iter;

            for(iter=clist.begin();iter!=clist.end();iter++)
            {
               cout<< iter->getname()<<endl;
               time_print(iter->gettime());
               cout<<"  midterm "<< iter->getmgrade() << "   final "<<iter->getfgrade()<<endl;
               cout<<"  commons "<< iter->getcommons()<<endl;
               cout<<"  note " << iter->getnote()<<endl;
            }

        }

        else if (intemp=="add")
        {
            pair< list<course>::iterator,bool > tpair; //// add_subject 的返回类型
            tpair=stu.add_subject( make_course());	//	插入
            if (tpair.second==false) {cout<<" fail to add course "<<endl;}	// 插入失败
            else  if (tpair.second==true) {cout<<" succedd to add course "<<endl;}	//插入成功
        }


        else if(intemp=="note")
        {
            string _note;
            cout<<"  current note:    " << stu.getnote()<<endl;
            cout<<"    enter a new note (n for not changing)  "<<endl;

            getline(cin, _note);
            cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream
            stu.setnote(_note);

        }
        else if (intemp=="exit")
            break;

    }//// end of for

}//// end of function







void time_print (course::times time)
{
	cout<<" year " << time.year<< "  Term"<<time.term<< "  Block: " <<time.block<<endl;
}


course make_course()
{
    string _name ;
    cout<<"     Please enter the name of the course "<<endl;
    cin>>_name;
    cin.ignore( numeric_limits<streamsize>::max(),'\n');    //// clean up input stream
    course::times _time;
	_time=make_time();
	course _course(_name,_time);
	return _course;
}

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
