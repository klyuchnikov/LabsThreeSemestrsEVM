#ifndef DecDef
#define DecDef

class Dec
{
public:
	Dec();
	~Dec();
	void PushFront(int value);
	void PushBack(int value);
	int PopFront();
	int PopBack();
	void Clear();
private:
	class Elem
	{
	public:
		Elem(Elem *prev, Elem *next, int value);
		~Elem();
		Elem *prev;
		Elem *next;
		int value;
	};
	Elem *head;
	Elem *tail;
	int count;
};

#endif