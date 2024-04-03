#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record
{
	char name[17];
	char product[12];
	unsigned short unitCount;
	float cost;
	struct Date date;
	char max[12];
};


void myCentr(string s, int wLine) {

	int w = s.length();
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	cout.width(delta + 1); cout << " ";

}

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}

void Draw(struct Record* records) {
	cout << endl;	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78);  cout << left << "|Офисные пакеты"; cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|      Фирма     ";
	cout << left << "| Количество продуктов ";
	cout << left << "| Объем продажи  ($)  ";
	cout << left << "| Часть ранка (%)";
	cout << left << " | Дата основания";
	cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 4; i++) {
		cout << left << "|"; cout.width(14); cout << left << records[i].name;
		cout << left << "|"; cout.width(14); cout << left << records[i].product;
		cout << left << "|"; cout.width(24); cout << left << records[i].unitCount;
		cout << left; cout.width(-1); cout << left << records[i].max;
		std::cout.precision(2);
		cout << left << "|"; cout.width(9); cout << left << fixed << records[i].cost;
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 11);
		cout << "|" << endl;
	}
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78);  cout << left << "|Примечание: по данным GartnerGroup за 1999г"; cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record Table[10];

	Table[0] = { "Oracle","+ 1",2488000000,"31.1" , {01,02,2010} };
	Table[1] = { "IBM","+ 3",2392000000,"29.9" , {02,03,2020} };
	Table[2] = { "Microsoft","+ 2",1048000000,"13.1", {12,12,2012} };
	Draw(Table);
}
