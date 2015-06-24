#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;
using std::vector;

void changeone(int &a)
{
	a +=20;
}

int main ()
{
    string name ="hellow";
    string path;
    path = name+"\\"+name+".s";
        cout<<path<<endl;

}
