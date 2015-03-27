#include<vector>
#include<string>
#include"course.cpp"

using std::string;
using std::vector;

class student
{
public:

	string getname() {return name;}
	void setname(string a){name=a;}

	int addcourse(string course_name)
	{
		if ()	// if there is no same course
		{
			course temp(course_name);
			subjects.push_back(temp);
			return 1;
		}
		else	// if there is same named course, return 0 [give out warning
		{
			course temp(course_name);
			subjects.push_back(temp);
			return 0;
		 }

	}

private:

	string name ;
	vector<course> subjects ;
	int gradute ;




};
