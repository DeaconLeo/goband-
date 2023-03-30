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
void searchByNo(std::set<Flight>*);//按航班号查找 
void searchByDest(std::set<Flight>*);// 按目的地查找 
void deleteFlight(std::set<Flight>*);//删除单个航班 
void deleteFlightBulk(std::set<Flight>*);//批量删除
void addFlight(std::set<Flight>*);//加入单个航班 
void addFlightBulk(std::set<Flight>*);//批量添加 
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
	std::cout << std::endl<< "感谢您使用本航班管理系统！" << std::endl;
	return 0;
}


class Flight
{
public:
	Flight(){}
	~Flight(){}
	void addPlane();
	void dispFlight();
	//将对象内部的英文缩写，转成汉语输出 
	const char* getAirport(char ch[])
	{
		if (strcmp(ch, "ZH") == 0)return "珠海";
		else if (strcmp(ch, "BJ") == 0)return "北京";
		else if (strcmp(ch, "SH") == 0)return "上海";
		else if (strcmp(ch, "HZ") == 0)return "杭州";
		else if (strcmp(ch, "HK") == 0)return "香港";
		else if (strcmp(ch, "CQ") == 0)return "重庆";
		else return "UNKNOWN";
	}
	const char* getType(char ch[])
	{
		if (strcmp(ch, "BOEING737") == 0)return "波音737";
		else if (strcmp(ch, "BOEING787") == 0)return "波音787";
		else if (strcmp(ch, "BOEING777") == 0)return "波音777";
		else if (strcmp(ch, "AIRBUSA350") == 0)return "空客A350";
		else if (strcmp(ch, "AIRBUSA330") == 0)return "空客A330";
		else return "UNKNOWN";
	}
	const char* getCompany(char ch[])
	{
		if (strcmp(ch, "MU") == 0)return "中国东方航空公司";
		else if (strcmp(ch, "CA") == 0)return "中国国际航空公司";
		else if (strcmp(ch, "CZ") == 0)return "中国南方航空公司";
		else if (strcmp(ch, "HU") == 0)return "中国海南航空公司";
		else if (strcmp(ch, "ZH") == 0)return "中国深圳航空公司";
		else return "UNKNOWN";
	}
	bool operator<(const Flight& f) const { return strcmp(f.planeNo, this->planeNo) > 0; }//set的比较运算符重载 

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
		std::cout << "       航班数据管理        " << std::endl;
		std::cout << "|--------------------------|" << std::endl;
		std::cout << "|        功能选择          |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|     1.批量输入航班       |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|     2.显示全部航班       |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|     3.新增单次航班       |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|     4.删除单次航班       |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|     5.批量删除航班       |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|     6.退回主菜单         |" << std::endl;
		std::cout << "请选择功能：";
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
		std::cout << "     航班信息查询系统      " << std::endl;
		std::cout << "|--------------------------|" << std::endl;
		std::cout << "|        功能选择          |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|   1.按航班号查询         |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|   2.按起点站--终点站查询 |" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|   3.退回主菜单           |" << std::endl;
		std::cout << "请选择功能：";
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
	std::cout << "     航班信息查询系统     " << std::endl;
	std::cout << "*                          *" << std::endl;
	std::cout << "*---------主菜单-----------*" << std::endl;
	std::cout << "*                          *" << std::endl;
	std::cout << "*     1.航班数据管理       *" << std::endl;
	std::cout << "*                          *" << std::endl;
	std::cout << "*     2.查询航班信息       *" << std::endl;
	std::cout << "*                          *" << std::endl;
	std::cout << "*     3.退出系统           *" << std::endl;
	std::cout << "请选择菜单：";
}

std::set<Flight>* loadFile(void)
{
	bool flag_initial = false;
	std::fstream ifile("flightManage.dat", std::ios::in | std::ios::binary);
	if (!ifile)
	{
		std::cout << " 不能打开文件 :" << "flightManage.dat" << std::endl;
		exit(1);
		flag_initial = true;
	}
	if (!flag_initial)
	{
		const int Plen = sizeof(class Flight);
		std::set<Flight>* p = new std::set<Flight>;//初始化
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
		std::cout << " 不能建立文件 :" << "flightManage.dat" << std::endl;
		exit(1);
	}
	else std::cout<< std::endl<<"存储文件成功！"<< std::endl;
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
	std::cout << "请输入要删除的航班号：" ;
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
	if (flag){p->erase(i); std::cout << "删除成功！" << std::endl;}
	else { std::cout << "抱歉，您所输入的航班号不存在" << std::endl; }

}

void deleteFlightBulk(std::set<Flight>* p)
{
	size_t n,n_test=p->size();
	std::cout << "请输入批量删除的航班数：";
	std::cin >> n;
	std::cout << "请输入要批量删除的航班号：";
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
		std::cout << "全部删除成功！" << std::endl;
		std::cout << "删除成功航班数：" << n_test- p->size() << std::endl;
	}
	else if(n_test- p->size() == 0){
		std::cout << "输入的航班号全部不存在" << std::endl;
		std::cout << "删除成功航班数：" << n_test- p->size() << std::endl;
	}
	else{
		std::cout << "输入的航班号部分不存在" << std::endl;
		std::cout << "删除成功航班数：" << n_test- p->size() << std::endl;
	}
}

void addFlight(std::set<Flight>* p)
{
	std::cout << "请输入要增加的航班:航班号  起点站  终点站  班期  起飞时间  到达时间  机型  票价  航空公司" << std::endl;
	Flight temp;
	size_t n_test = p->size();
	temp.addPlane();
	p->insert(temp);
	if (p->size() - n_test == 1) {
		std::cout << "添加成功！" << std::endl;
	}
	else { std::cout << "存在相同航班号的航班,添加失败" << std::endl; }
}

void addFlightBulk(std::set<Flight>* p)
{
	size_t n, n_test = p->size();
	std::cout << "请输入批量输入的航班数：";
	std::cin >> n;
	std::cout << std::endl << "请批量输入：航班号  起点站  终点站  班期  起飞时间  到达时间  机型  票价  航空公司" << std::endl;
	Flight* temp;
	for (size_t i = 0; i < n; i++)
	{
		temp = new Flight;
		temp->addPlane();
		p->insert(*temp);
		temp->~Flight();
	}
	if (p->size() - n_test == n) {
		std::cout << "添加成功！" << std::endl;
	}
	else {
		std::cout << "存在相同航班号的航班" << std::endl;
		std::cout << "输入成功航班数：" << p->size() - n_test << std::endl;
	}
}

void searchByNo(std::set<Flight>* p)
{
	std::cout << "请输入要查询的航班号：";
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
		std::cout << std::endl << "查找成功！该趟航班信息为：" << std::endl << std::endl;
		std::cout << "航班号   起点站   终点站   班期     起飞时间   到达时间   机型      票价   航空公司   " << std::endl;
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
		((Flight)*i).dispFlight();
	}
	else { std::cout << "抱歉，您所输入的航班号不存在" << std::endl; }
}

void searchByDest(std::set<Flight>* p)
{
	int flag = 0;
	std::string start;
	std::string end;
	std::cout << "请输入起始站：";
	std::cin >> start;
	std::cout << std::endl;
	std::cout << "请输入终点站：";
	std::cin >> end;
	std::cout << std::endl;
	std::set<Flight>::iterator i;
	for (i = p->begin(); i != p->end(); i++)
	{
		if (((Flight)*i).getAirport((char*)i->startAirport) == start && ((Flight)*i).getAirport((char*)i->endAirport) == end) {
			flag++;
			if (flag==1)
			{
				std::cout << std::endl << "查找成功！航班信息为：" << std::endl << std::endl;
				std::cout << "航班号   起点站   终点站   班期     起飞时间   到达时间   机型      票价   航空公司   " << std::endl;
				std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
			}
			((Flight)*i).dispFlight();
		}
	}
	if (flag) std::cout << "共查找到"<<flag<<"趟符合的航班" << std::endl;
	else std::cout << "抱歉，未查找到对应出发点与终点站的航班" << std::endl;
}

void dispAll(std::set<Flight>* p)
{
	std::cout << std::endl << "全部航班信息如下:" << std::endl<<std::endl;
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
	std::cout << "航班号   起点站   终点站   班期     起飞时间   到达时间   机型      票价   航空公司   " << std::endl;
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
	std::set<Flight>::iterator i;
	for (i = p->begin(); i != p->end(); i++)
	{
		((Flight)*i).dispFlight();
	}
}

