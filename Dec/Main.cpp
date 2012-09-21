// Map.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dec.h"
#include <iostream>
#include "conio.h"

using namespace std;

void  menu()
{
	Dec *dec = new Dec;
	char c;
	do
	{
		printf("1: PushFront\n");
		printf("2: PushBack\n");
		printf("3: PopFront\n");
		printf("4: PopBack\n");
    printf("5: Clear\n");
		printf("\nEsc: Exit\n");
		c = getch();
		int val;
		switch(c)
		{
		case '1': 
			cout << "PushFront: Please input value: ";

			cin >> val;
			dec->PushFront(val);
			cout << endl; break;
		case '2': 
			cout << "PushBack: Please input value: ";
			cin >> val;
			dec->PushBack(val);
			cout << endl; break;
		case '3': 
			cout << "PopFront: ";
			val = dec->PopFront();
			cout << val << endl; break;
		case '4': 
			cout << "PopBack: ";
			val = dec->PopBack();
			cout << val << endl; break;
		case '5': 
   		dec->Clear();  cout << endl; break;
		}
	} while(c != 27);
	delete dec;
}

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	menu();
}