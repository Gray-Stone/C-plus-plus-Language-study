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
		int cheack_time (){return year*10+term;} // ����ͬһ��ѧ����ͬѧ����ͬ���Ŀ�ʱ����Ƚ���
	};

		//���캯��

	course():name("untitled course"),fgrade(-1),mgrade(-1),time(),commons() ,note() {}	//�տγ�

	course(string _name):name(_name),fgrade(-1),mgrade(-1),time(),commons() {}			//ֻ������
	course(string _name, times _time) :name(_name),fgrade(-1),mgrade(-1),time(_time),commons(),note() {}//���ֺ�ʱ��
	course(string _name,times _time,int _fgrade) :name(_name),fgrade(_fgrade),mgrade(-1),time(_time),commons(),note() {}//����ʱ�����ĩ�ɼ�
	course(string _name,times _time,int _fgrade,int _mgrade) :name(_name),fgrade(_fgrade),mgrade(_mgrade),time(_time),commons(),note(){}//����ʱ����ĩ�ɼ������гɼ�

		// end
	void setname (string a) {name=a;}	// ��������
	string getname (){return name;}		// ��������

	void setfgrade (int fgrade) {this->fgrade=fgrade;}	//�������гɼ�
	void setmgrade (int mgrade) {this->mgrade=mgrade;}	//������ĩ�ɼ�

	void setcommons(string common) { commons=common;}	//��������
	string getcommons () {return commons;}				//��������


private:
	string name;		//�γ�����
	int fgrade;			//��ĩ�ɼ�
	int mgrade;			//���гɼ�
	struct times time;	//�γ�ʱ��
	string commons;		//����
	string note;		//��ע
};
