#include<iostream>
#include<new>
using namespace std;
/*
 * @brief: generic stack class demo
 * @author: Lalatendu
 */
template<class Type>
class Stack { // uses template here
	int index;
	Type* tos;
public:
	int size;
	Stack(int sz = 1) { // default to 1
		index = 0;
		if (sz < 1) // if negative is entered reset to 1
			size = 1;
		else
			size = sz;
		try {
			tos = new Type[size];
		} catch (bad_alloc xa) {
			cout << "error allocation. \n";
			return;
		} // array initialized
	}
	int get_index() {
		return this->index;
	}
	void print_stk() {
		cout << '\n' << "Printing stack: ";
		for (int i = 0; i < index; i++) {
			cout << tos[i] << ' ';
		}
		cout << '\n';
	} // prints stack linearly
	void push(Type i) {
		if (index < 0)
			index++;
		if (index > size - 1) { // size is not 0 based but index is
			cout << "PUSH: Stack full.\n";
			return;
		} else tos[index++] = i;
	}
	int pop(bool isLIFO) {
		if (index < 0) {
			cout << "POP: Stack out of bounds " << '\n';
			return -1;
		}
		if (index == 0) { index--; return tos[0]; } // is stack has run out...
		if (isLIFO == true) // last in first out
			return tos[--index];
		int temp = tos[0]; // to use later for return
		for (int i = 0; i < index; i++)
			tos[i] = tos[i + 1]; // reassign
		index--;
		return temp;
	}
	~Stack() {
		delete[]tos; // release memory
	}
};

int main(int argc, char* argv[]) {
	Stack <int> s = 10;
	cout << "Stack size: " << s.size << "\n";
	for (int i = 0; i < 15; i++) s.push(i);
	for (int j = 0; j < 15; j++) cout << s.pop(false);
	for (int i = 0; i < 15; i++) s.push(i);
	s.print_stk();
	cout << s.pop(true); cout << s.pop(false);
	s.print_stk();
	s.push(23);
	s.print_stk();
	cout << s.pop(true);
	s.print_stk();
	return 0;
}