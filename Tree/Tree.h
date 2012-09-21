#ifndef treeDef
#define treeDef

class Tree
{
public:
	Tree();
	~Tree();
	void Add(int);
	void Delete(int);
	bool Exists(int);
	void Print();
	void Clear();
private:
	class Elem
	{
	public:
		Elem(Elem *, Elem *, int);
		~Elem();
		Elem *right;
		Elem *left;
		int value;
	};
	Elem *tree;
	int count;
	void addElem(Elem *&, int);
	void deleteElem(Elem *&, int);
	void printElem(Elem *&, int);
	void replaceRight(Elem *&root, Elem *&right);
	void clearElem(Elem *&root);
	bool ExistsElem(Elem *, int);
};
#endif