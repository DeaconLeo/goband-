#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <iomanip>
#include <string.h>

class Flight; 
void draw_menu();//menu 
void dispAll(std::set<Flight>*);//display all flights
void flightDataManage(std::set<Flight>*);//menu
void searchFlight(std::set<Flight>* );//menu
void searchByNo(std::set<Flight>*);//������Ų��� 
void searchByDest(std::set<Flight>*);// ��Ŀ�ĵز��� 
void deleteFlight(std::set<Flight>*);//ɾ���������� 
void deleteFlightBulk(std::set<Flight>*);//����ɾ��
void addFlight(std::set<Flight>*);//���뵥������ 
void addFlightBulk(std::set<Flight>*);//������� 
//file load and save
std::set<Flight>* loadFile(void);
void saveFile(std::set<Flight>*);
//flag_exit
static bool flag_end = false;

int main()
{

	std::set<Flight>* p = loadFile();
	while (true)
	{
		draw_menu();
		int flag;

		std::cin >> flag;

		switch (flag)
		{
		case 1:
		{
			flightDataManage(p);
		}break;
		case 2:
		{
			searchFlight(p);
		}break;
		case 3:
		{flag_end = true; }break;
		default:break;
		}
		if(flag_end)break;
		system("cls");
	}
	saveFile(p);
	std::cout << std::endl<< "��л��ʹ�ñ��������ϵͳ��" << std::endl;
	return 0;
}


class Flight
{
public:
	Flight(){}
	~Flight(){}
	void addPlane();
	void dispFlight();
	//�������ڲ���Ӣ����д��ת�ɺ������ 
	const char* getAirport(char ch[])
	{
		if (strcmp(ch, "ZH") == 0)return "�麣";
		else if (strcmp(ch, "BJ") == 0)return "����";
		else if (strcmp(ch, "SH") == 0)return "�Ϻ�";
		else if (strcmp(ch, "HZ") == 0)return "����";
		else if (strcmp(ch, "HK") == 0)return "���";
		else if (strcmp(ch, "CQ") == 0)return "����";
		else return "UNKNOWN";
	}
	const char* getType(char ch[])
	{
		if (strcmp(ch, "BOEING737") == 0)return "����737";
		else if (strcmp(ch, "BOEING787") == 0)return "����787";
		else if (strcmp(ch, "BOEING777") == 0)return "����777";
		else if (strcmp(ch, "AIRBUSA350") == 0)return "�տ�A350";
		else if (strcmp(ch, "AIRBUSA330") == 0)return "�տ�A330";
		else return "UNKNOWN";
	}
	const char* getCompany(char ch[])
	{
		if (strcmp(ch, "MU") == 0)return "�й��������չ�˾";
		else if (strcmp(ch, "CA") == 0)return "�й����ʺ��չ�˾";
		else if (strcmp(ch, "CZ") == 0)return "�й��Ϸ����չ�˾";
		else if (strcmp(ch, "HU") == 0)return "�й����Ϻ��չ�˾";
		else if (strcmp(ch, "ZH") == 0)return "�й����ں��չ�˾";
		else return "UNKNOWN";
	}
	bool operator<(const Flight& f) const { return strcmp(f.planeNo, this->planeNo) > 0; }//set�ıȽ���������� 

	char planeNo[15];
	char startAirport[15];
	char endAirport[15];
	char startTime[15];
	char endTime[15];
	char planeType[15];
	char Price[15];
	char airCompany[15];
	char schedule[15];
};

void Flight::addPlane()
{
	std::cin >> planeNo >> startAirport >> endAirport >> schedule >> startTime >> endTime >> planeType >> Price >> airCompany ;
}

void Flight::dispFlight()
{
	std::cout.flags(std::ios::left);
	std::cout << std::setw(9) << planeNo << std::setw(9) << getAirport(startAirport) << std::setw(9) << getAirport(endAirport);
	std::cout << std::setw(9) << schedule << std::setw(11) << startTime << std::setw(11) << endTime;
	std::cout << std::setw(10) << getType(planeType) << std::setw(7) << Price << std::setw(10) << getCompany(airCompany) << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
}

void flightDataManage(std::set<Flight>* p)
{
	bool backMenu = false;
	while (true)
	{
		std::cout << std::endl;
		std::cout << "       �������ݹ���        " << std::endl;
		std::cout << "|--------------------------|" << std::endl;
		std::cout << "|        ����ѡ��          |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|     1.�������뺽��       |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|     2.��ʾȫ������       |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|     3.�������κ���       |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|     4.ɾ�����κ���       |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|     5.����ɾ������       |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|     6.�˻����˵�         |" << std::endl;
		std::cout << "��ѡ���ܣ�";
		int flag;
		std::cin >> flag;
		switch (flag)
		{
		case 1:
		{
			addFlightBulk(p);
		}break;
		case 2:
		{
			dispAll(p);
		}break;
		case 3:
		{
			addFlight(p);
		}break;
		case 4:
		{
			deleteFlight(p);
		}break;
		case 5:
		{
			deleteFlightBulk(p);
		}break;
		case 6:
		{
			backMenu = true;
		}break;
		default:break;
		}
		if (backMenu) break;
	}

}

void searchFlight(std::set<Flight>* p)
{
	bool backMenu = false;
	while (true)
	{
		std::cout << std::endl ;
		std::cout << "     ������Ϣ��ѯϵͳ      " << std::endl;
		std::cout << "|--------------------------|" << std::endl;
		std::cout << "|        ����ѡ��          |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|   1.������Ų�ѯ         |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|   2.�����վ--�յ�վ��ѯ |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|   3.�˻����˵�           |" << std::endl;
		std::cout << "��ѡ���ܣ�";
		int flag;
		std::cin >> flag;
		switch (flag)
		{
		case 1:
		{
			searchByNo(p);
		}break;
		case 2:
		{
			searchByDest(p);
		}break;
		case 3:
		{
			backMenu = true;
		}break;
		default:break;
		}
		if(backMenu)break;
	}
}

void draw_menu()
{
	std::cout << std::endl;
	std::cout << "     ������Ϣ��ѯϵͳ     " << std::endl;
	std::cout << "*                          *" << std::endl;
	std::cout << "*---------���˵�-----------*" << std::endl;
	std::cout << "*                          *" << std::endl;
	std::cout << "*     1.�������ݹ���       *" << std::endl;
	std::cout << "*                          *" << std::endl;
	std::cout << "*     2.��ѯ������Ϣ       *" << std::endl;
	std::cout << "*                          *" << std::endl;
	std::cout << "*     3.�˳�ϵͳ           *" << std::endl;
	std::cout << "��ѡ��˵���";
}

std::set<Flight>* loadFile(void)
{
	bool flag_initial = false;
	std::fstream ifile("flightManage.dat", std::ios::in | std::ios::binary);
	if (!ifile)
	{
		std::cout << " ���ܴ��ļ� :" << "flightManage.dat" << std::endl;
		exit(1);
		flag_initial = true;
	}
	if (!flag_initial)
	{
		const int Plen = sizeof(class Flight);
		std::set<Flight>* p = new std::set<Flight>;//��ʼ��
		size_t length;
		ifile.read((char*)&length, sizeof(size_t));
		for (size_t i = 0; i < length; i++)
		{
			Flight temp;
			ifile.read((char*)&temp, Plen);
			p->insert(temp);
			temp.~Flight();
		}
		ifile.close();
		return p;
	}
	else
	{
		std::set<Flight>* p = new std::set<Flight>;
		return p;
	}
}

void saveFile(std::set<Flight>* p)
{
	std::fstream ofile("flightManage.dat", std::ios::out | std::ios::binary);
	if (!ofile)
	{
		std::cout << " ���ܽ����ļ� :" << "flightManage.dat" << std::endl;
		exit(1);
	}
	else std::cout<< std::endl<<"�洢�ļ��ɹ���"<< std::endl;
	const int Plen = sizeof(class Flight);
	std::set<Flight>::iterator i;
	size_t length = p->size();
	ofile.write((char*)&length, sizeof(size_t));
	for (i = p->begin(); i != p->end(); i++)
	{
		Flight temp = *i;
		ofile.write((char*)&temp, Plen);
		temp.~Flight();
	}
	ofile.close();
}

void deleteFlight(std::set<Flight>* p)
{
	std::cout << "������Ҫɾ���ĺ���ţ�" ;
	std::string strDel;
	std::cin >> strDel;
	bool flag = false;
	std::set<Flight>::iterator i;
	for (i = p->begin(); i != p->end(); i++)
	{
		if (i->planeNo == strDel){
			flag = true;
			break;
		}
	}
	if (flag){p->erase(i); std::cout << "ɾ���ɹ���" << std::endl;}
	else { std::cout << "��Ǹ����������ĺ���Ų�����" << std::endl; }

}

void deleteFlightBulk(std::set<Flight>* p)
{
	size_t n,n_test=p->size();
	std::cout << "����������ɾ���ĺ�������";
	std::cin >> n;
	std::cout << "������Ҫ����ɾ���ĺ���ţ�";
	std::set<Flight>::iterator i;
	for (size_t ii = 0; ii < n; ii++)
	{
		std::string strDel; 
		std::cin>>strDel;
		for (i = p->begin(); i != p->end(); i++)
		{
			if (i->planeNo == strDel){
			p->erase(*i); 
			break;
			}
		}
	}
	std::cout<< std::endl;
	if (n_test- p->size() == n) {
		std::cout << "ȫ��ɾ���ɹ���" << std::endl;
		std::cout << "ɾ���ɹ���������" << n_test- p->size() << std::endl;
	}
	else if(n_test- p->size() == 0){
		std::cout << "����ĺ����ȫ��������" << std::endl;
		std::cout << "ɾ���ɹ���������" << n_test- p->size() << std::endl;
	}
	else{
		std::cout << "����ĺ���Ų��ֲ�����" << std::endl;
		std::cout << "ɾ���ɹ���������" << n_test- p->size() << std::endl;
	}
}

void addFlight(std::set<Flight>* p)
{
	std::cout << "������Ҫ���ӵĺ���:�����  ���վ  �յ�վ  ����  ���ʱ��  ����ʱ��  ����  Ʊ��  ���չ�˾" << std::endl;
	Flight temp;
	size_t n_test = p->size();
	temp.addPlane();
	p->insert(temp);
	if (p->size() - n_test == 1) {
		std::cout << "��ӳɹ���" << std::endl;
	}
	else { std::cout << "������ͬ����ŵĺ���,���ʧ��" << std::endl; }
}

void addFlightBulk(std::set<Flight>* p)
{
	size_t n, n_test = p->size();
	std::cout << "��������������ĺ�������";
	std::cin >> n;
	std::cout << std::endl << "���������룺�����  ���վ  �յ�վ  ����  ���ʱ��  ����ʱ��  ����  Ʊ��  ���չ�˾" << std::endl;
	Flight* temp;
	for (size_t i = 0; i < n; i++)
	{
		temp = new Flight;
		temp->addPlane();
		p->insert(*temp);
		temp->~Flight();
	}
	if (p->size() - n_test == n) {
		std::cout << "��ӳɹ���" << std::endl;
	}
	else {
		std::cout << "������ͬ����ŵĺ���" << std::endl;
		std::cout << "����ɹ���������" << p->size() - n_test << std::endl;
	}
}

void searchByNo(std::set<Flight>* p)
{
	std::cout << "������Ҫ��ѯ�ĺ���ţ�";
	std::string str;
	std::cin >> str;
	bool flag = false;
	std::set<Flight>::iterator i;
	for (i = p->begin(); i != p->end(); i++)
	{
		if (i->planeNo == str) {
			flag = true;
			break;
		}
	}
	if (flag) {
		std::cout << std::endl << "���ҳɹ������˺�����ϢΪ��" << std::endl << std::endl;
		std::cout << "�����   ���վ   �յ�վ   ����     ���ʱ��   ����ʱ��   ����      Ʊ��   ���չ�˾   " << std::endl;
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
		((Flight)*i).dispFlight();
	}
	else { std::cout << "��Ǹ����������ĺ���Ų�����" << std::endl; }
}

void searchByDest(std::set<Flight>* p)
{
	int flag = 0;
	std::string start;
	std::string end;
	std::cout << "��������ʼվ��";
	std::cin >> start;
	std::cout << std::endl;
	std::cout << "�������յ�վ��";
	std::cin >> end;
	std::cout << std::endl;
	std::set<Flight>::iterator i;
	for (i = p->begin(); i != p->end(); i++)
	{
		if (((Flight)*i).getAirport((char*)i->startAirport) == start && ((Flight)*i).getAirport((char*)i->endAirport) == end) {
			flag++;
			if (flag==1)
			{
				std::cout << std::endl << "���ҳɹ���������ϢΪ��" << std::endl << std::endl;
				std::cout << "�����   ���վ   �յ�վ   ����     ���ʱ��   ����ʱ��   ����      Ʊ��   ���չ�˾   " << std::endl;
				std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
			}
			((Flight)*i).dispFlight();
		}
	}
	if (flag) std::cout << "�����ҵ�"<<flag<<"�˷��ϵĺ���" << std::endl;
	else std::cout << "��Ǹ��δ���ҵ���Ӧ���������յ�վ�ĺ���" << std::endl;
}

void dispAll(std::set<Flight>* p)
{
	std::cout << std::endl << "ȫ��������Ϣ����:" << std::endl<<std::endl;
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
	std::cout << "�����   ���վ   �յ�վ   ����     ���ʱ��   ����ʱ��   ����      Ʊ��   ���չ�˾   " << std::endl;
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
	std::set<Flight>::iterator i;
	for (i = p->begin(); i != p->end(); i++)
	{
		((Flight)*i).dispFlight();
	}
}

