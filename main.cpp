#include <iostream>
#include <fstream>
#include "stuff.h"
using namespace std;

void addStuff();
void deleteStuff();
void displayStuff();
bool searchStuff();
void newdata();

int main()
{
	//stuff test;
	//char a[20], b[20];
	//cin >> a >> b;
	//test.initial(a, b);
	//test.display();
	//初始化
	//newdata();
	//操作指引
	int selector;

	while (true) {
		cout << "退出请按0" << endl;
		cout << "添加物品请按1" << endl;
		cout << "删除物品请按2" << endl;
		cout << "查找物品请按3" << endl;
		cout << "显示所有物品信息请按4" << endl;
		cin >> selector;
		if (selector == 0) break;
		switch (selector) {
			case 1:addStuff(); break;
			case 2:deleteStuff(); break;
			case 3:searchStuff(); break;
			case 4:displayStuff(); break;
		}
		cout << '\n';
	}


	return 0;
}