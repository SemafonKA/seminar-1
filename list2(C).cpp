#include <iostream>
using namespace std;

class Stack
{
  public:
	int *values;
	int index, capacity;
	Stack(void)
	{
		index = 0;
		capacity = 2;
		values = (int *)malloc(sizeof(int) * capacity);
	}

	~Stack()
	{
		free(values);
	}

	void ifOverflow(void)
	{
		if (index == capacity)
		{
			capacity *= 2;
			values = (int *)realloc(values, sizeof(int) * capacity);
		}
	}

	void push(int x)
	{
		++index;
		ifOverflow();
		values[index - 1] = x;
	}

	int back(void)
	{
		if(index > 0) return values[index - 1];
		return 0;
	}

	int pop(void)
	{
		if (index > 0)
		{
			--index;
			return values[index];
		}
		return 0;
	}
	
	bool isEmpty(void) { return index == 0; }
	
	void makeNull(void) { index = 0; }
};

int main(int argc, char *argv[])
{

}
