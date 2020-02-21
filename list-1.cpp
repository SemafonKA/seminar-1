#include <iostream>
#include <string>
using namespace std;

class Stack
{
  public:
	class ListElt
	{
	  public:
		ListElt *next;
		int data;
		ListElt(int x) : next(nullptr), data(x){};
	};

	ListElt *first;

	Stack() : first(nullptr){};

	~Stack()
	{
		makenull();
	}
	void push(int x)
	{
		ListElt *el = new ListElt(x);
		el->next = first;
		first = el;
	}

	int pop(void)
	{
		if (isEmpty()) return -65536;
		int data = first->data;
		ListElt *el = first;
		first = first->next;
		delete el;
		return data;
	}

	int front(void)
	{
		return first->data;
	}

	bool isEmpty(void) { return first == nullptr; }

	void makenull(void)
	{
		ListElt *del;
		while (first)
		{
			del = first;
			first = first->next;
			delete del;
		}
	}
};

int main(int argc, char *argv[])
{
	string str;
	Stack stack;
	cout << "Калькулятор постфикс записи" << endl << "Вводить через пробел, конец - \"stop\"" << endl << "> ";
	cin >> str;
	while (str != "stop")
	{
		if (isdigit(str[0])) {
			stack.push(stoi(str));
		}
		else if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
		{
			int a = stack.pop();
			int b = stack.pop();
			int c{};
			if (str[0] == '+')
				c = b + a;
			else if (str[0] == '-')
				c = b - a;
			else if (str[0] == '*')
				c = b * a;
			else
				c = b / a;
			stack.push(c);
		}
		cin >> str;
	}
	cout << "Answer: " << stack.pop() << endl;
	return 0;
