#ifndef MapDef
#define MapDef

class Map
{
public:
	Map();
	~Map();
	void Add(int key, int value);
  int Find(int key);
	void Delete(int key);
	void Clear();

private:
	class Elem
	{
	public:
		int key;
		int value;
		Elem *right;
		Elem *left;
		Elem(Elem *right, Elem *left, int key, int value);
		~Elem();
	};
	Elem *tree;
	int count;
	void AddElem(Elem *&root, int key, int value);
	void DeleteElem(Elem *&root, int key);
	int FindElem(Elem *&root, int key);
	void ClearElem(Elem *&root);
	void Replace(Elem *&root, Elem *&right);
};




#endif