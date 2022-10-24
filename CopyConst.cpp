#include<iostream>
using namespace std;
/*
 * @brief: try to find out why copy constructor
 * is required.
 */
class A {
	int* p;
public:
	A() {
		try { p = new int[5]; } catch (bad_alloc a) {
			cout << "alloc fail.";
		}
	}
	A(const A& a) {
		try { p = new int[5]; } catch (bad_alloc a) {
			cout << "alloc fail.";
		}
	};
	~A() {
		delete[] p;
	};
	A A::operator=(A a){
		try{p=new int[5];}catch(bad_alloc a){
			cout << "alloc fail.";
		}
		return *this;
	};
	void print_memory() { cout << p << '\n'; }
};
int main(void) {
	A a, b;
	a.print_memory();
	b.print_memory();
	b = a;
	a.print_memory();
	b.print_memory();
	return 0;
}