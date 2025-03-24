/**/

#include <iostream>
using namespace std;

class Base {
public:
	void func1() { cout << "Base::func1()" << endl; }

};

class Derived : public Base {
public:	
	void func() { cout << "Derived::func()" << endl; }
	void func1() { cout << "Derived::func1()" << endl; }
};

class Derived2 : public Derived {
public:
	void func() { cout << "Derived2::func()" << endl; }
	void func1() { cout << "Derived2::func1()" << endl; }
};

int main() {

	Base* bptr;
	Derived dobj;

	bptr = static_cast<Base*>(&dobj);	//upcasting 
	bptr->func1();

	Base bobj;
	Derived* dptr;
	dptr = static_cast<Derived*>(&bobj);	//downcasting
	dptr->func();
	dptr->func1();

	Derived2* dptr2 = static_cast<Derived2*>(dptr);
	dptr2->func();
	dptr2->func1();

	return 0;
}