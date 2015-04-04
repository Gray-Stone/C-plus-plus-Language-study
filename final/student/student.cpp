#include<vector>
#include<list>
#include<string>
#include"course.cpp"

using std::string;
using std::vector;
using std::list;



class student
{
public:

	string getname() {return name;}
	void setname(string a){name=a;}

	list<course>::iterator add_subject(string course_name, course::times time) // add a subject with only name and time
	{
		list<course>::iterator iter;
		for (iter= subject.begin();iter!=subject.end();iter++)
		{
			if(course_name < iter->getname())	if (time.check_time()>iter->checktime()) 	{break;}
			// warning for logical check
			// check_time and checktime is defined in struct times and class course it should point to same thing.
		}
		course temp(course_name ,time) ;
		subject.insert(iter,temp);
		--iter;
		return iter;
	}

	int add_subject(string course_name, course::times time ,int mgrade)	// add a subject with name time and midtrem
	{
		list<course>::iterator iter;
		iter=add_subject(course_name,time);
        iter->setmgrade(mgrade);
	}

	int add_subject(string course_name, course::times time , int mgrade,int fgrade)	// add a subject with name time and final
	{
		list<course>::iterator iter;
		iter=add_subject(course_name,time);

        iter->setmgrade(mgrade);
         iter->setfgrade(fgrade);
	}

	course exist_course (string name,course::times _time)
	{
		list<course>::iterator iter;
		for (iter = subject.begin();  iter!=subject.end();iter++)
		{
			if (!(iter->getname() < name ))
				if (iter->getname() == name )
					if (iter->checktime()== _time.check_time() )break;
		}

		return *(--iter);
	}


private:


	string name ;
	list<course> subject;
//	list<course>::iterator iter;	//doesn't seem necessary

	string note;





};
