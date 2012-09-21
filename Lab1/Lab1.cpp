#include "stdafx.h"
#include "PRIORITYQUEUE.h"
#include <iostream>
#include <assert.h>
#include <conio.h>
#include <string.h>

using namespace std;

#define MAX 10
const char separators[] = " ,./:";
const char enableEN[] = "qwertyuiopasdfghjklzxcvbnm0123456789QWERTYUIOPLKJHGFDSAZXCVBNM";
const char enableRU[] = "éöóêåíãøùçõúıæäëîğïàâûôÿ÷ñìèòüáşÉÖÓÊÅÍÃØÙÇÕÚİÆÄËÎĞÏÀÂÛÔß×ÑÌÈÒÜÁŞ¸¨";

Element::Element()
{}
Element::Element(char *val, int _key)
{
	key = _key;
	value = val;
}

void Input::twip(char *&str)
{
	if (str[0] != '0')
	{
		if (str[0] != '-' && str[1] == '0')
			return;
		if (str[1] != '0')
			return;
	}
	int size = strlen(str);
	char *temp = new char[size];
	int i = (str[0] == '-') ? 1 : 0;
	int k = i;
	if (str[0] == '-')
		temp[0] = '-';
	bool flag = false;
	while (i < size)
	{
		if (flag == false && str[i++] == '0')
			continue;
		flag = true;
		temp[k++] = str[(--i)++];
	}
	temp[k] = '\0';
	delete str;
	str = temp;
}
int Input::ReadKey()
{
	int  n = 0;
	char ch = 0;
	int k = 0;
	do 
	{
		char *str = new char[15];
		bool flag = false;
		cout << "Please input key: ";
		while (true)
		{
			ch = _getch();
			if (ch == 13)
			{
				str[k] = '\0';
				cout << endl;
				k = 0;
				twip(str);
				if (strlen(str) > ((str[0] == '-') ? 11 : 10))
					break;
				char *max = "2147483648";
				char *s = (str[0] == '-') ? &str[1] : str;
				int maxLen = (str[0] == '-') ? 11 : 10;
				if (strcmp(s, max) > 1 && strlen(str) == maxLen)
					break;
				n = atoi(str);
				break;
			}
			if (strchr(enableEN, ch) != NULL && k < 14)
			{
				if (ch == '-' && (flag == true || k != 0))
					continue;
				if (ch == '-')
					flag = true;
				str[k++] = ch; 
				cout << ch;
			}			
		}
		delete str;
	} while (n == 0);
	return n;
}

char *Input::ReadValue()
{
	char str[150];
	char ch = 0;
	int k = 0;
	char *el;
	cout << "Please input value < 150 symbol: ";
	while (true)
	{
		ch = _getch();
		if (ch == 13 && k > 0 )
		{
			str[k] = '\0';
			el = new char[++k];
			strcpy(el, str);			
			cout << endl;
			return el;
		}
		if (strchr(separators, ch) != NULL || strchr(enableEN, ch) != NULL && k < 149)
		{
			str[k++] = ch; 
			cout << ch;
		}
	}
}



Queue::Queue()
{
	count = 0;
}
Queue::~Queue()
{
	for (int i = 0; i < count; i++)
		delete el[i].value;
}
void Queue::Add()
{
	InsertTask(Input::ReadValue(), Input::ReadKey());
}
void Queue::InsertTask(char *val, int key)
{
	if (key > 10)
	{
		cout << "Error: Key > 10" << "\n";
		delete val;
		getch();
		return;
	}
	if (count + 1 == MAX)
	{	
		cout << "Error: Queue MAX" << "\n";
		delete val;
		getch();
		return;
	}
	for (int i = 0; i < count; i++)
	{
		if (el[i].key == key)
		{
			for (int j = count; j >= i + 1; j--)
				el[j] = el[j - 1];
			el[i].value = val;
			el[i].key = key;
			count++;
			cout << "Task added" << endl;
			getch();
			return;
		}
	}		
	if (count == 0)
	{
		el[0].value = val;
		el[0].key = key;
		count++;
		cout << "Task added" << endl;
		getch();
		return;
	}
	if (key < el[0].key)
	{
		for (int j = count; j > 0; j--)
			el[j] = el[j - 1];
		el[0].value = val;
		el[0].key = key;
		count++;
		cout << "Task added" << endl;
		getch();
		return;
	}
	el[count].value = val;
	el[count].key = key;
	count++;
	cout << "Task added" << endl;
	getch();
	return;
}

void Queue::Clear()
{
	for (int i = 0; i < count; i++)
		delete el[i].value; 
	cout << "Query was clear" << endl;
	getch();
	count = 0;
}
void Queue::Print()
{
	if (count == 0)
	{
		cout << "Query is empty" << endl;
		getch();
		return;
	}
	for (int i = 0; i < count; i++)
		cout << "Task: Priory - " << el[i].key << " ; Value - " << el[i].value << endl;
	getch();
}
void Queue::GetMaximum(bool deleteElement)
{
	if (count == 0)
	{
		cout << "Query is empty" << endl;
		getch();
		return;
	}
	Element *temp = new Element;
	temp->key = el[0].key;
	temp->value = new char[strlen(el[0].value) + 1];
	strcpy(temp->value, el[0].value);
	if (deleteElement)
	{
		delete el[0].value;
		for (int i = 0; i < count - 1; i++)
			el[i] = el[i + 1];
		count--;
	}
	cout << "Task with maximum priory: Priory - " << temp->key << " ; Value - " << temp->value << endl;
	getch();
	delete temp->value;
	delete temp;
	return;
}

void  menu(Queue *q)
{
	char c;
	do
	{
		printf("1: Get task with maximum priory without delete: \n");
		printf("2: Get task with maximum priory with delete: \n");
		printf("3: Print Query task\n");
		printf("4: Add task\n");
		printf("5: Clear\n");
		printf("\nEsc: Exit\n");
		c = getch();
		switch(c)
		{
		case '1': q->GetMaximum(false); break;
		case '2': q->GetMaximum(true); break;
		case '3': q->Print(); break;
		case '4': q->Add(); break;
		case '5': q->Clear(); break;
		}
	} while(c != 27);
}

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Queue *q = new Queue(); 
	menu(q);
	delete q;
}

