// Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Tree.h"
#include "Queue.h"
using namespace std;


void  menu()
{
	Tree *tree = new Tree;
	char c;
	do
	{
		printf("1: View\n");
		printf("2: Find\n");
		printf("3: Add\n");
		printf("4: Del\n");
		printf("5: Clear\n");
		printf("\nEsc: Exit\n");
		c = getch();
		switch(c)
		{
		case '1': 
			cout << "Print:";
			tree->Print();
			cout << endl; break;
		case '2': 
			cout << "Find:";
			int val;
			cin >> val;
			bool flag;
			flag = tree->Exists(val); 
			cout << (flag == true ? "true" : "false") << endl; break;
		case '3': 
			cout << "Add:";
			int add;
			cin >> add;
			tree->Add(add); cout << endl; break;
		case '4': 
			cout << "Delete:";
			int del;
			cin >> del;
			tree->Delete(del); cout << endl; break;
		case '5': tree->Clear();  cout << endl; break;
		}
	} while(c != 27);
	delete tree;
}


void  menuQueue()
{
	Queue *queue = new Queue;
	char c;
	do
	{
		printf("1: Push\n");
		printf("2: Pop\n");
		printf("3: IsEmpty\n");
		printf("\nEsc: Exit\n");
		c = getch();
		switch(c)
		{
		case '1': 
			cout << "Push:";
			int val;
			cin >> val;
			queue->Push(val);
			cout << endl; break;
		case '2': 
			cout << "Pop:";
			int v;
			v = queue->Pop();
			cout << v << endl; break;
		case '3': 
			cout << "IsEmpty:";
			bool flag = queue->IsEmpty();
			cout << ( flag == true ? "true" : "false") << endl; break;
		}
	} while(c != 27);
	delete queue;
}


void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	menuQueue();
}