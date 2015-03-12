#include <string>

using std::string ;

class person_adress
{

public:
	person_adress():name("undefine"),adress("undefine"){}

	person_adress(string Name,string Adress):name(Name), adress (Adress) {}

	string getname () { return name ;}
	string getadress () {return adress;}

	string setname (string Name) {this-> name = Name ; return this->name;} ;
	string setadress (string Adress) {this->adress = Adress ; return this -> adress;}

private:
	string name;
	string adress;

};
