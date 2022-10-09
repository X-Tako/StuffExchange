#include <iostream>
#include <fstream>
#include <cstring>
#include "stuff.h"
using namespace std;

void stuff::initial(char a[20], char b[20])
{
	strcpy_s(item,a);
	strcpy_s(owner,b);
	flag = 1;
}

void stuff::display()
{
	cout << "��Ʒ���ƣ�" << item << ' ' << "ӵ���ߣ�" << owner << endl;
}

void newdata()
{
	ofstream outfile("C:\\Users\\Yunxi H\\Documents\\temp\\stuffdata.txt");
	while (!outfile) {
		cout << "error" << endl;
		return;
	}
	outfile.close();
}


void addStuff()
{
	char itemd[20], onwerd[20];

	//���������Ʒ�ļ�¼
	cout << "��������Ʒ�����ƣ�";
	cin >> itemd;
	cout << "�������������֣�";
	cin >> onwerd;
	stuff *tmp;
	tmp = new stuff;
	(* tmp).initial(itemd, onwerd);

	fstream outfile("C:\\Users\\Yunxi H\\Documents\\temp\\stuffdata.txt");
	while (!outfile) {
		cout << "�ļ��򿪴���" << endl;
		return;
	}

	//д��stuffdata�ļ�
	outfile.seekp(0, ios::end);
	outfile.write((char*) tmp, sizeof(*tmp));

	delete tmp;
	outfile.close();

}


void deleteStuff()
{
	char itemd[20],ownerd[20];
	bool find=0;

	cout << "������Ҫɾ����Ʒ�����ƣ�";
	cin >> itemd;
	cout << "������Ҫɾ����Ʒ��ӵ���ߣ�";
	cin >> ownerd;
	stuff* tmp;
	tmp = new stuff;

	fstream infile("C:\\Users\\Yunxi H\\Documents\\temp\\stuffdata.txt");
	while (!infile) {
		cout << "�ļ��򿪴���" << endl;
		return;
	}

	//��������Ʒ
	infile.seekg(0);
	while (infile.peek()!=EOF)
	{
		infile.read((char*) tmp, sizeof(*tmp));
		if (strcmp(itemd, tmp->item) == 0 && strcmp(ownerd, tmp->owner) == 0 && tmp->flag == 1)
		{
			find = 1;
			cout << "�ҵ�����ɾ������Ʒ"<<endl; 
			tmp->flag=0; 
			int back = 0-sizeof(stuff);
			infile.seekp(back,ios::cur);
			infile.write((char*)tmp, sizeof(*tmp));
			break;
		}
	}
	//cout << strcmp(itemd, tmp->item) << endl;
	//cout << itemd<< tmp->item << endl;
	//cout << tmp->flag;
	if (find == 0)	cout << "�޸���Ʒ��Ϣ,ɾ����Ч"<<endl;

	delete tmp;
	infile.close();
}


void displayStuff()
{
	ifstream infile("C:\\Users\\Yunxi H\\Documents\\temp\\stuffdata.txt");
	while (!infile) {
		cout << "�ļ��򿪴���" << endl;
		return;
	}
	infile.seekg(0);
	stuff* tmp;
	tmp = new stuff;

	while (infile.peek()!=EOF)
	{
		infile.read((char*) tmp, sizeof(stuff));
		if (tmp->flag)	tmp->display();
		//cout << tmp->flag;
	}
	
	delete tmp;
	infile.close();
}

bool searchStuff()
{
	char itemd[20];
	stuff* tmp;
	tmp = new stuff;
	bool find = 0;

	cout << "��������Ʒ���ƣ�";
	cin >> itemd;

	fstream infile("C:\\Users\\Yunxi H\\Documents\\temp\\stuffdata.txt");
	while (!infile) {
		cout << "�ļ��򿪴���" << endl;
		return 0;
	}

	while (infile.peek() != EOF)
	{
		infile.read((char*)tmp, sizeof(*tmp));
		if (strcmp(itemd, tmp->item) == 0 && tmp->flag==1) 
		{
			cout << "�ҵ�������Ʒ��Ϣ��" << endl;
			tmp->display(); 
			find = 1; 
			//break;
		}
	}

	if (find == 0)	{ cout << "�޸���Ʒ��Ϣ"<<endl; }
	
	delete tmp;
	infile.close();
	return find;
}

