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
	//��ʼ��
	//newdata();
	//����ָ��
	int selector;

	while (true) {
		cout << "�˳��밴0" << endl;
		cout << "�����Ʒ�밴1" << endl;
		cout << "ɾ����Ʒ�밴2" << endl;
		cout << "������Ʒ�밴3" << endl;
		cout << "��ʾ������Ʒ��Ϣ�밴4" << endl;
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