#include "stdafx.h"
#include "Queue.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

Queue::Queue()
{
	count = 0;
}
Queue::~Queue(){}
void Queue::Push(int val)
{
	if (count == SIZE)
	{
		cout << "Size max!" << endl;
		return;
	}
	if (val == 0)
	{
		cout << "value error" << endl;
		return;
	}
	for (int i = count - 1; i >=0; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[0] = val;
	count++;
}
int Queue::Pop()
{
	if (count == 0)
	{
		cout << "IsEmpty " << endl;
		return 0;
	}
	int res = arr[count - 1];
	arr[count - 1] = 0;
	count--;
	return res;
}
bool Queue::IsEmpty()
{
	if (count == 0)
		return true;
	else
		return false;
}