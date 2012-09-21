#ifndef HashDef
#define HashDef

#define NHASH 13

class Dictionary
{
public:
	void Add(int key, int value);
	int Find(int key);
	void Delete(int key);
	void Clear();
  Dictionary();
	~Dictionary();
private:
	class Elem
	{
	public:
		int key;
		int value;
		Elem *next;
		Elem(Elem *next, int key, int value);
		~Elem();
	};
	Elem *arr[NHASH];
	int hash(int key);
	bool Exists(int ind, int key);
};

#endif
