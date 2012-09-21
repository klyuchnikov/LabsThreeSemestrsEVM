#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#define MAX 10

typedef class Element
{
public:
	int key;
	char* value;
	Element();
	Element(char *val, int _key);
};

typedef class Input
{
private:
	static void twip(char *&str);
public:
	static int ReadKey();
	static char *ReadValue();
};

typedef class Queue
{
private:
	Element el[MAX];
	int count;
public:
	Queue();
	~Queue();
	void Add();
	void InsertTask(char *val, int key);
	void Clear();
	void Print();
	void GetMaximum(bool deleteElement);
};
#endif 