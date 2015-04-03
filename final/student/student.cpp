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

	int add_subject(string course_name, course::times time)
	{
		for (iter= subject.begin();iter!=subject.end();iter++)
		{
			if(course_name < iter->getname)
		}
	}
	int add_subject(string course_name, int fgrade)
	{

	}
	int add_subject(string course_name, int fgrade, int mgrade)
	{

	}

private:


	string name ;
	list<course> subject;
	list<course>::iterator iter;

	string note;





};
