#include <string>
#include <vector>

using std::string;
class course
{
public:
	struct times
	{
		int year;
		int term ;
		char block;
		int check_time (){return year*10+term;} // 用于同一个学生不同学期上同样的课时排序比较用
	};

		//构造函数

	course():name("untitled course"),fgrade(-1),mgrade(-1),time(),commons() ,note() {}	//空课程

	course(string _name, times _time) :name(_name),fgrade(-1),mgrade(-1),time(_time),commons(),note() {}//名字和时间

		// end
	void setname (string a) {name=a;}	// 更改名字
	string getname (){return name;}		// 返回名字

	void setfgrade (int fgrade) {this->fgrade=fgrade;}	//更改期中成绩
	void setmgrade (int mgrade) {this->mgrade=mgrade;}	//更改期末成绩

	void setcommons(string common) { commons=common;}	//更改评语
	string getcommons () {return commons;}				//返回评语

	int checktime ()
	{
		return time.check_time();
	}


private:
	string name;		//课程名字
	int fgrade;			//期末成绩
	int mgrade;			//期中成绩
	struct times time;	//课程时间
	string commons;		//评论
	string note;		//附注
};
