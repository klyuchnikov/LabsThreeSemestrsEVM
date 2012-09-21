#ifndef queueDef
#define queueDef

#define SIZE 10

class Queue
{
public:
	void Push(int);
	int Pop();
	bool IsEmpty();
	Queue();
	~Queue();

private:
	int count;
	static int size;
	int arr[SIZE];
};




#endif