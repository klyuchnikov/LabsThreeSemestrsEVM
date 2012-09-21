#include "stdafx.h"
#include "Map.h"
#include <iostream>
#include "stdio.h"

using namespace std;

Map::Elem::Elem(Map::Elem *right, Map::Elem *left, int key, int value)
{
	this->key = key;
	this->left = left;
	this->right = right;
	this->value = value;
}
Map::Elem::~Elem() {}
Map::Map()
{
	tree = NULL;
	count = 0;
}
Map::~Map()
{
	ClearElem(tree);
}
void Map::Clear()
{
	ClearElem(tree);
	count = 0;
}
void Map::ClearElem(Map::Elem *&root)
{
	if (root == NULL)
		return;
	ClearElem(root->left);
	ClearElem(root->right);
	delete root;
	root = NULL;
}
void Map::Add(int key, int value)
{
	AddElem(tree, key, value);
}
void Map::AddElem(Map::Elem *&root, int key, int value)
{
	if (root == NULL)
	{
		Elem *el = new Elem(NULL, NULL, key, value);
		root = el;
		count++;
		return;
	}
	else if (key < root->key)
		AddElem(root->left, key, value);
	else if (key > root->key)
		AddElem(root->right, key, value);
}
int Map::Find(int key)
{
	return FindElem(tree, key);
}
int Map::FindElem(Map::Elem *&root, int key)
{
	if (root == NULL)
		return 0;
	else if (root->key == key)
		return root->value;
	else if (key < root->key)
		FindElem(root->left, key);
	else if (key > root->key)
		FindElem(root->right, key);
}
void Map::Delete(int key)
{
	DeleteElem(tree, key);
}
void Map::DeleteElem(Map::Elem *&root, int key)
{
	if (root == NULL)
		return;
	if (root->key == key)
	{
		if (root->left ==NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
			count--;
		}
		else if (root->left == NULL)
		{
			Elem *del = root;
			root = root->right;
			delete del;
			count--;
		}
		else if (root->right == NULL)
		{
			Elem *del = root;
			root = root->left;
			delete del;
			count--;
		}
		else
			Replace(root, root->left);
	}
	else if (root->key > key)
		DeleteElem(root->left, key);
	else
		DeleteElem(root->right, key);
}
void Map::Replace(Map::Elem *&root, Map::Elem *&right)
{
	if (right->right != NULL)
		Replace(root, right->right);
	else
	{
		Elem *newRoot = right;
		right = right->left;
		newRoot->left = root->left;
		newRoot->right = root->right;
		delete root;
		root = newRoot;
		count--;
	}
}