#include<iostream>
using namespace std;
class A
{
	int size;
	int *p;
  public:
	  A(int size = 1)
	{
		this->size = size;
		try
		{
			p = new int[size];
		} catch(bad_alloc xa)
		{
			cout << "alloc fail." << '\n';
		}
		//for(int i=0;i<size;i++) p[i]=i;
	};
	~A()
	{
		delete[]p;
	}
	/*
	A(const A & o)
	{
		int i;
		try
		{
			p = new int[size];
		} catch(bad_alloc xa)
		{
			cout << "alloc fail." << '\n';
		}
		for (i = 0; i < size; i++)
			p[i] = o.p[i];
	};*/
	void print_p(){
		cout << "Address: " << p << '\n';
		for(int i=0;i<size;i++) cout << p[i] << ' ';
		cout << '\n';
	}
};
int main(){
	A a, b(30);
	a.print_p();
	b.print_p();
	b=a;
	a.print_p();
	a=b;
	b.print_p();
	return 0;
}
