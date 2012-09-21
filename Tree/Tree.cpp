#include "stdafx.h"
#include "Tree.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

Tree::Elem::Elem(Tree::Elem *right, Tree::Elem *left, int val){
	this->right = right;
	this->left = left;
	this->value = val;
}
Tree::Elem::~Elem() {}
Tree::Tree(){
	tree = NULL;
	count = 0;
}
Tree::~Tree(){
	Clear();
	tree = NULL;
}
void Tree::Clear(){
	clearElem(tree);
	count = 0;
	cout << "Clear!";
}
void Tree::clearElem(Tree::Elem *&root){
	if (root == NULL)
		return;
	clearElem(root->left);
	clearElem(root->right);
	delete root;
	root = NULL;
}
void Tree::Add(int val){
	addElem(tree, val);
}
void Tree::addElem(Tree::Elem *&root, int val){
	if (root == NULL)	{
		Elem *el = new Elem(NULL, NULL, val);
		root = el;
		count++;
		return;
	}
	else if (val < root->value)
		addElem(root->left, val);
	else if (val > root->value)
		addElem(root->right, val);
}
void Tree::Print(){
	cout << endl;
	printElem(tree, 0);
	getch();
}
void Tree::printElem(Tree::Elem *&root, int level){
	if (root == NULL)
		return;
	printElem(root->right, level + 1);
	for (int i = 0; i < level * 4 + 2; i++)
		cout << " ";
	cout << "--" << root->value << endl;
	printElem(root->left, level + 1);
}
void Tree::Delete(int val){
	deleteElem(tree, val);
}
void Tree::deleteElem(Tree::Elem *&root, int val){
	if (root == NULL)	{
		cout << "Deleted not" << endl;
		return;
	}
	if (root->value == val)	{
		if (root->left == NULL && root->right == NULL)		{
			delete root;
			root = NULL;
			count--;
			cout << "Deleted" << endl;
		}
		else if (root->left == NULL)		{
			Elem *del = root;
			root = root->right;
			delete del;
			count--;
			cout << "Deleted" << endl;
		}
		else if (root->right == NULL)		{
			Elem *del = root;
			root = root->left;
			delete del;
			count--;
			cout << "Deleted" << endl;
		}
		else
			replaceRight(root, root->left);
	}
	else if (val < root->value)
		deleteElem(root->left, val);
	else if (val > root->value)
		deleteElem(root->right, val);
}
void Tree::replaceRight(Tree::Elem *&root, Tree::Elem *&right){
	if (right->right != NULL)
		replaceRight(root, right->right);
	else	{
		Elem *newRoot = right;
		right = right->left;
		newRoot->right = root->right;
		newRoot->left = root->left;
		delete root;
		root = newRoot;
		count--;
		cout << "Deleted" << endl;
		return;
	}
	cout << "Deleted not!!!" << endl;
}
bool Tree::Exists(int val){
	return ExistsElem(tree, val);
}
bool Tree::ExistsElem(Tree::Elem *root, int val){
	if (root == NULL)
		return false;
	else if (root->value == val)
		return true;
	else if (val < root->value)
		return ExistsElem(root->left, val);
	else
		return ExistsElem(root->right, val);
}