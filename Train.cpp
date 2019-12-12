#include "Train.h"
#include <iostream>

using namespace std;

//ostream& operator<<(ostream& os, Train& obj)
//{
//	Train* temp = NULL;
//	os << "����� ������: " << temp->number_train << endl;
//	os << "����� ���������� ������: " << temp->name << endl;
//	os << "����� �����������: " << temp->hour << ":" << temp->minutes << endl;
//	return os;
//}
istream& operator>>(istream& is, Train* obj2)
{
	string str;
	int num;
	int time1;
	int time2;
	do {
		system("cls");
		cout << "����� �����������(2 ����� ����� ������): ";
		cin >> time1 >> time2;
		if (time1 < 0 || time2 < 0 || 23 < time1 || 59 < time2)
		{
			cout << "������: ������� �������� ��� ����� 0 - 23, ��� ����� 0 - 59";
			cout << "\n �������: " << time1 << " " << time2;
			system("pause");
			continue;
		}

		try {
			cout << "����� ������: ";
			cin >> num;
		}
		catch (...)
		{
			cin.clear();
			cout << "������: ������� ������������ �������� (������� �����)";
			system("pause");
			continue;
		}

		cout << "����� ����������: ";
		cin >> str;
		
		break;
	} while (true);
	obj2->number_train = num;
	obj2->name = str;
	obj2->hour = time1;
	obj2->minutes = time2;
	return is;
}

Train::Train()
{
	this->name = name;
	this->number_train = number_train;
	this->hour = hour;
	this->minutes = minutes;
	head = NULL;
	last = NULL;
	last_2 = NULL;
	size = 0;
}

Train::~Train()
{
}

void Train::Add()
{
	size++;
	Train* temp = new Train;
	cin >> temp;
	Set_tail(temp);
	temp->next = NULL;
	if (Get_head() == NULL)
	{
		Set_head(temp);
		Set_last_2(temp);
		temp->last = NULL;
		system("cls");
		return;
	}
	temp->last = Get_last_2();
	Get_last_2()->next = temp;
	Set_last_2(temp);
	system("cls");
}

////void Train::Delete()
//{
//}

void Train::Show()
{
	Train l;
	int p = 0;
	system("cls");
	Train* temp = NULL;
	if (Get_head() == NULL)
	{
		cout << "��� ������" << endl;
		system("pause");
		system("cls");
		return;
	}
	temp = Get_head();
	int* arr = new int [size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = temp->number_train;
		temp = temp->next;
	}
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	temp = Get_head();
	while (p < size)
	{
		if (arr[p] == temp->number_train)
		{

			cout << "����� ������: " << temp->number_train << endl;
			cout << "����� ���������� ������: " << temp->name << endl;
			cout << "����� �����������: " << temp->hour << ":" << temp->minutes << endl;
			cout << endl;
			temp = Get_head();
			p++;
			continue;
		}
		temp = temp->next;
	}
	system("pause");
	system("cls");
}
