#include<iostream>
#include<new>
using namespace std;
template<class Type> 
class Stack
{
	int index;
	Type *tos;
  public:
	int size;
	  Stack(int sz)
	{
		index = 0;
		if (sz < 1)
			size = 1;
		else
			size = sz;
		try
		{
			tos = new Type[size];
		} catch(bad_alloc xa)
		{
			cout << "error allocation. \n";
			return;
		}
	}
	int get_index()
	{
		return this->index;
	}
	void print_stk()
	{
		cout << '\n' << "Printing stack: ";
		for (int i = 0; i < index; i++)
		{
			cout << tos[i] << ' ';
		}
		cout << '\n';
	}
	void push(Type i)
	{
		if (index < 0)
			index++;
		if (index > size - 1)
		{
			cout << "Stack full.\n";
			return;
		}
		else
		{
			tos[index++] = i;
			cout << "D: stack in: " << i << '\n';
		}
	}
	int pop(bool isLIFO)
	{
		if (index < 0)
		{
			cout << "Stack out of bounds ";
			return -1;
		}
		if(index==0) { index--; return tos[0];}
		//if (index > size - 1)
		//	index--;
		if (isLIFO == true)
			return tos[--index];
		cout << '\n' << "pop2: index: " << this->get_index() << '\n';
		int temp = tos[0];
		for (int i = 0; i < index; i++)
			tos[i] = tos[i + 1];
		index--;
		return temp;
	}
	~Stack()
	{
		delete[]tos;
	}
};

int main(int argc, char *argv[])
{
	Stack <bool> s = 10;
	cout << "Stack size: " << s.size << "\n";
	for (int i = 0; i < 15; i++)
		s.push(i+0.7);
	for (int j = 0; j < 15; j++)
		cout << "D out: " << s.pop(false) << '\n';
	for (int i = 0; i < 15; i++)
		s.push(i+0.8);
		s.print_stk();
	cout << s.pop(true) << s.pop(false);
	s.print_stk();
	s.push(23.5);
	s.print_stk();
	cout << s.pop(true);
	return 0;
}
