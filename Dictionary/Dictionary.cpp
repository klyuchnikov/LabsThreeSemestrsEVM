#include "stdafx.h"
#include "Dictionary.h"
#include <iostream>
using namespace std;

Dictionary::Elem::Elem(Dictionary::Elem *next, int key, int value)
{
	this->next = next;
	this->key = key;
	this->value = value;
}
Dictionary::Elem::~Elem() {}
Dictionary::Dictionary()
{
	for (int i = 0; i < NHASH; i++)
		arr[i] = NULL;
}
Dictionary::~Dictionary()
{
	Clear();
}
int Dictionary::hash(int key)
{
	return key % NHASH;
}
void Dictionary::Add(int key, int value)
{
	int h = hash(key);
	if (Exists(h, key) == true)
	{
		cout << "Key Exist" << endl;
		return;
	}
	Elem *head = arr[h];
	Elem *el = new Elem(head, key, value);
  head = el;
  arr[h] = head;
}
bool Dictionary::Exists(int ind, int key)
{
	Elem *p = arr[ind];
  while(p != NULL)
	{
		if (p->key == key)
			return true;
		p = p->next;
	}
	return false;
}
int Dictionary::Find(int key)
{
	int h = hash(key);
	Elem *p = arr[h];
	while(p != NULL)
	{
		if (p->key == key)
			return p->value;
		p = p->next;
	}
	cout << "Not find";
	return 0;
}
void Dictionary::Delete(int key)
{
	int h = hash(key);
	Elem *p = arr[h];
	if (p == NULL)
	{
    cout << "Not Delete" << endl;
		return;
	}
	if (p->key == key)
	{
		Elem *del = p;
		p = p->next;
		delete del;
		cout << "Delete with key = " << key << endl;
		return;
	}
	while(p->next != NULL)
	{
		if (p->next->key == key)
		{
			Elem *del = p->next;
			p->next = del->next;
			delete del;
      cout << "Deleted with key = " << key << endl;
	  	return;
		}
		p = p->next;
	}
  cout << "Not Delete" << endl;
}
void Dictionary::Clear()
{
  for (int i = 0; i < NHASH; i++)
	{
		Elem *head = arr[i];
		while(head != NULL)
		{
			Elem *del = head;
			head = head->next;
			delete del;
		}
		arr[i] = NULL;
	}
}