#include "stdafx.h"
#include "Dec.h"
#include <iostream>
#include "conio.h"

Dec::Elem::Elem(Dec::Elem *prev, Dec::Elem *next, int value)
{
	this->next = next;
	this->prev = prev;
	this->value = value;
}
Dec::Elem::~Elem() {}
Dec::Dec()
{
	head = NULL;
	tail = NULL;
	count = 0;
}
Dec::~Dec()
{
	Clear();
}
void Dec::Clear()
{
	if (head == NULL)
		return;
	while (head != NULL)
	{
		Elem *p = head;
		head = head->next;
		delete p;
	}
	head = NULL;
	tail = NULL;
}
void Dec::PushFront(int value)
{
	Elem *el = new Elem(NULL, head, value);
	if (tail == NULL)
		tail = el;
	else
		head->prev = el;
	head = el;
	count++;
}
void Dec::PushBack(int value)
{
	Elem *el = new Elem(tail, NULL, value);
	if (head == NULL)
		head = el;
	else
		tail->next = el;
	tail = el;
	count++;
}
int Dec::PopFront()
{
	if (head == NULL)
		return 0;
  int res;
	Elem *del = head;
	res = head->value;
	if (head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
	 	head = head->next;
		head->prev = NULL;
	}
	delete del;
	count--;
	return res;
}
int Dec::PopBack()
{
	if (tail == NULL)
		return 0;
	int res;
	Elem *del = tail;
	res = tail->value;
	if (head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		tail = tail->prev;
		tail->next = NULL;
	}
	delete del;
	count--;
	return res;
}