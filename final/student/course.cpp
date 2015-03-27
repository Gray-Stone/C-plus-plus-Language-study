#include <string>
#include <vector>

using std::string;
class course
{
public:
	course():name("untitled name"),score(0),commons() {}
	course(string name):name(name),score(0),commons() {}

	void setname (string a) {name=a;}
	string getname (){return name;}
	void setcommons(string common) { commons=common;}

private:
	int score;
	string name;
	string commons;
};
