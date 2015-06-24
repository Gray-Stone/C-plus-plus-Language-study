#include <iostream>
#include <string>
#include <list>
#include <fstream>

using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ofstream;
using std::ifstream;
using std::ios;

////////////// a class of two names and two numbers //////////////
class num
{
	public:
	string name;
	int a,b;
	num(string _name, int _a, int _b): name(_name),a(_a),b(_b){;}
};



int main()
{
	list<num> a;
	string intemp;

	////////// load /////////////////

	ifstream nin("name.t",ios::in);
	ifstream fin ;

	num temp("non",-1,-1);
	for (;nin>>intemp;)
	{
		fin.open (intemp.c_str(),ios::in);
		fin>>temp.name;		//������name������ʱ������Ϊname��ƥ��Ļ�tempҲ���ᱻ���뵽list
		if (temp.name!="end");
		{
			fin>>temp.a;
			fin>>temp.b;
			a.push_back(temp);
		}
		fin.close ();
	}

	////////////////////////////////

	for (;;)
	{

		cout<<" add, print, save" <<endl;
		cin>>intemp;

		///////////////add //////////////////////
		if (intemp=="add")
		{
			for(;;)
			{

				num temp("non",-1,-1);
				cout<<"name, a, b   or exit"<<endl;
				cin>>temp.name;
				if ((temp.name)=="exit") break;
				cin>>temp.a>>temp.b;
				a.push_back(temp);
			}
		}
		////////// print /////////////////
		if (intemp=="print")
		{
			list<num>::iterator iter;
			cout<<endl;
			for(iter=a.begin();iter!=a.end();iter++){cout<<iter->name<<" "<<iter->a<<" "<<iter->b<<" "<<endl;}

			cout<<endl;
		}

		////////////////// save /////////////////
		if (intemp=="save")
		{

			ofstream nout("name.t",ios::out);
			list<num>::iterator iter;
			string _name;

			//// save every thing in file /////
			for (iter=a.begin();iter!=a.end();iter++)
			{
				nout<<iter->name<<endl;	//�������ļ����¼����

				ofstream fout (iter->name.c_str(),ios::out);

				fout<<iter->name<<endl;		//��¼num��Ϣ
				fout<<iter->a<<endl;
				fout<<iter->b<<endl;
				fout<<"end"<<endl;		//��Ǽ�¼���
				fout.close();
			}
//			nout<<"end"<<endl;		//��������ļ���¼���
			nout.close();
			////////////////////////
		}
		/////////////// exit /////////////
		if (intemp=="exit") break;
	}

}
