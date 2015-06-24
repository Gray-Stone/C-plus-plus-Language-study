#include<vector>
#include<list>
#include<utility>
#include<string>
#include"course.cpp"
#include <fstream>
#include <iostream>
#include <direct.h> /////       _mkdir () ////////////

using std::string;
using std::vector;
using std::list;
using std::pair;
using std::make_pair;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::endl;



class student
{
public:

	student(string _name):name(_name){;}
	student(): name("unnamed"),note("no note"){;}

	string getname() {return this->name;}
	void setname(string a){name=a;}
	string getnote() {return this->note;}
	void setnote(string _note) {note=_note;}
	list<course> getallcourse() {return this->subject;}

//////////////////////////////////////




//////////////////////////////////////
//// adding subjects
//// first
	pair< list<course>::iterator,bool > add_subject(string course_name, course::times time) // add a subject with only name and time
	{
		list<course>::iterator iter;
		for (iter= subject.begin();iter!=subject.end();iter++)
		{
			if(course_name <= iter->getname())
			{break;	}
			// warning for logical check
			// check_time and checktime is defined in struct times and class course it should point to same thing.
		}
		if(course_name == iter->getname())
		{
			for(;time.check_time() < iter->checktime() && iter!=subject.end();iter++)
			{
			}
			if(time.check_time() == iter->checktime())
				return make_pair(iter,false);	//if there are same course in same time. there will be a error
		}

//		course temp(course_name ,time) ;
		subject.insert(iter,course(course_name ,time));
		--iter;
		return make_pair(iter,true);
	}
//// second

	pair< list<course>::iterator,bool > add_subject(string course_name, course::times time ,int mgrade)	// add a subject with name time and midtrem
	{
		pair< list<course>::iterator , bool > temp;
		list<course>::iterator iter;
		temp =add_subject(course_name,time);

		if (temp.second)
			return make_pair(iter,false);
		else
		{
        iter->setmgrade(mgrade);
        return make_pair(iter,true);
		}
	}

//// third
	pair< list<course>::iterator,bool > add_subject(string course_name, course::times time , int mgrade,int fgrade)	// add a subject with name time and final
	{
		pair< list<course>::iterator,bool > temp;
		list<course>::iterator iter;
		temp =add_subject(course_name,time);
		if (temp.second)
			return make_pair(iter,false);
		else
		{
         iter->setfgrade(fgrade);
         return make_pair(iter,true);
		}
	}

///// direct use course
//// need fix
	pair< list<course>::iterator,bool > add_subject( course _course )
	{
		list<course>::iterator iter;
			for (iter= subject.begin();iter!=subject.end();iter++)
			{
				if( _course.getname() <= iter->getname())
				{break;	}
				// warning for logical check
				// check_time and checktime is defined in struct times and class course it should point to same thing.
			}
			if(_course.getname()== iter->getname())
			{
				for(; _course.checktime() < iter->checktime() && iter!=subject.end();iter++)
				{
				}
				if( _course.checktime() == iter->checktime())
					return make_pair(iter,false);	//if there are same course in same time. there will be a error
			}

			subject.insert(iter,_course);
			--iter;
			return make_pair(iter,true);
	}

/////////////////////////////////////



/////////////////////////////////////
//check course exeist
//  if the course exeist, return the iter and ture
//  if not exeist, return the
	pair< list<course>::iterator,int > exist_course (string _name,course::times _time)
	{
		list<course>::iterator iter;
		for (iter = subject.begin(); iter!=subject.end() && (iter->getname() <= _name );iter++)
		{
				if (iter->getname() == _name )
					if (iter->checktime()== _time.check_time() )
						return make_pair(iter,1);
		}
		return make_pair(iter,0);
	}

// check for mutipal course
	pair< list<course>::iterator,int > exist_course (string _name)
	{
		list<course>::iterator iter1;
		list<course>::iterator iter2;
		int i ;
		for (iter1= subject.begin() ; iter1!=subject.end() ; ++iter1)
		{
			if ( iter1->getname() == name)
				{
					for (iter2=iter1, i=1 ; iter2!=subject.end();++iter2,++i)
						if (iter2->getname() != _name)
							break;
					return make_pair(iter1,i);
				}
		}

		return make_pair (iter2,0);
	}

// return all course within this term
	list<course> course_term (course::times _time)
	{
		list<course> rt;
		list<course>::iterator iter;
		for (iter=subject.begin(); iter!=subject.end();iter++)
		{
            if (iter->checktime()==_time.check_time())
			{
				rt.push_back(*iter);
			}
		}
		return rt;
	}


////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// saving
	int save()
	{
	    ////// 创造文件夹 /////////////
	    _mkdir(name.c_str());
	    string path;        //// not in use ///
        path = name+"\\"+name+".s" ;

		ofstream fout (  (path+name+".s").c_str(),ios::out);	// need change s

		list<course>::iterator iter;
		int amount;

		///// Save student personal information //////
		fout<<"personal info"<<endl;
		fout<<name<<endl;
		fout<<note<<endl;
		fout<<"EOnote"<<endl;

		///////// save course info /////////
		for (iter=subject.begin(),amount=0;iter!=subject.end();iter++,amount++)
		{
			fout<<iter->getname()<<endl;	// 在学生的文件里创造课程的列表
			iter->save(path);
		}
		return amount;
	}





private:


	string name ;
	list<course> subject;
//	list<course>::iterator iter;	//doesn't seem necessary
	string note= "no note";
};
