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
		int check_time (){return year*10+term;} // ����ͬһ��ѧ����ͬѧ����ͬ���Ŀ�ʱ����Ƚ���
	};

		//���캯��

	course():name("untitled course"),fgrade(-1),mgrade(-1),time(),commons() ,note() {}	//�տγ�

	course(string _name, times _time) :name(_name),fgrade(-1),mgrade(-1),time(_time),commons(),note() {}//���ֺ�ʱ��

		// end
	void setname (string a) {name=a;}	// ��������
	string getname (){return name;}		// ��������

	void setfgrade (int fgrade) {this->fgrade=fgrade;}	//�������гɼ�
	void setmgrade (int mgrade) {this->mgrade=mgrade;}	//������ĩ�ɼ�

	void setcommons(string common) { commons=common;}	//��������
	string getcommons () {return commons;}				//��������

	int checktime ()
	{
		return time.check_time();
	}


private:
	string name;		//�γ�����
	int fgrade;			//��ĩ�ɼ�
	int mgrade;			//���гɼ�
	struct times time;	//�γ�ʱ��
	string commons;		//����
	string note;		//��ע
};
