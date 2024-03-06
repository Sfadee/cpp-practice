#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};
struct Record
{
	char transportType[12];
	char route[5];
	long long lengthRoute;
	char timeMin[5];
	struct Date date;
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
void printWhithZero(int num, int width) {
	if (num > 999 and num < 10000) {
		cout.width(width + 1);
		cout << right << "00" << num;
	}
	if (num > 9999 and num < 100000) {
		cout.width(width);
		cout << right << "0" << num;
	}
}
void Draw(struct Record* records) {
	int width = 78 + 16;
	cout << endl; cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width); cout << left << "|Фирмы - производители СКБД"; cout << "| " << endl;
		cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|      Фирма     ";
	cout << left << "| Количество продуктов ";
	cout << left << "| Объем продажи  ($) ";
	cout << left << "| Часть ранка (%)";
	cout << left << " |Дата основания|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << left << "|"; cout.width(16); cout << left << records[i].transportType;
		cout << left << "|"; cout.width(22); cout << left << records[i].route;
		cout.precision(3);
		cout << left << "| "; cout << left << fixed << records[i].lengthRoute;
		cout.fill(' '); cout.width(8); cout << left << " ";
		cout << left << " ";
		cout << left << "|"; cout.width(17); cout << left << records[i].timeMin;
		//cout << left << "|"; cout.width(20); cout << left; myCentr(records[i].timeMin, 22);
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 17);
		cout << "|" << endl;
	}
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width); cout << left << "|Примечание: по данным GartnerGroup за 1999г"; cout << "| " << endl;
		cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct Record records[10];
	records[0] = { "Oracle","+ 1",2488000000,"31.1" , {01,02,2010}};
	records[1] = { "IBM","+ 3",2392000000,"29.9" , {02,03,2020}};
	records[2] = { "Microsoft","+ 2",1048000000,"13.1", {12,12,2012}};
	Draw(records);
}