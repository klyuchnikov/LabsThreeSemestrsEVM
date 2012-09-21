// Map.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Map.h"
#include <iostream>
#include "conio.h"

using namespace std;

void  menu()
{
	Map *dict = new Map;
	char c;
	do
	{
		printf("1: Add\n");
		printf("2: Find\n");
		printf("3: Del\n");
		printf("4: Clear\n");
		printf("\nEsc: Exit\n");
		c = getch();
		switch(c)
		{
		case '1': 
			cout << "Please input key: ";
			int key;
			cin >> key;
			cout << "Please input value: ";
			int val;
			cin >> val;
			dict->Add(key, val);
			cout << endl; break;
		case '2': 
			cout << "Find: ";
			int find;
			cin >> find;
			cout << endl; 
			int res;
			res = dict->Find(find);
			cout << res << endl; break;
		case '3': 
			cout << "Delete:";
			int del;
			cin >> del;
			dict->Delete(del); cout << endl; break;
		case '5': 
   		dict->Clear();  cout << endl; break;
		}
	} while(c != 27);
	delete dict;
}

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	menu();
}