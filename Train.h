#pragma once
#include <iostream>
#include <string>

using namespace std;

class Train
{
private:
	int size;
	Train* head;
	Train* tail;
	Train* last_2;
public:
	Train();
	~Train();
	string name;
	int number_train;
	int hour;
	int minutes;
	//friend ostream& operator <<(ostream& os, Train& obj);
	friend istream& operator >>(istream& is, Train* obj2);
	Train* next;
	Train* last;
	void Add();
	//void Delete();
	void Show();
	void Set_head(Train* head)
	{
		this->head = head;
	}
	Train* Get_head()
	{
		return head;
	}
	void Set_last_2(Train* last_2)
	{
		this->last_2 = last_2;
	}
	Train* Get_last_2()
	{
		return last_2;
	}
	void Set_tail(Train* tail)
	{
		this->tail = tail;
	}
	Train* Get_tail()
	{
		return tail;
	}
};