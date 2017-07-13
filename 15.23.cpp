/* 假设D1类需要覆盖它继承而来的fcn函数，你应该如何对其进行修改？
	如果你修改之后fcn匹配了Base中的定义，则该节的调用语句将如何解析？
*/
#include<iostream>

class Base {
public:
	virtual int fcn() { std::cout << "Base::fcn()" << std::endl; return 0; }	
};

class D1 : public Base {
	// 覆盖base的fcn
public:
	virtual int fcn() override { std::cout << "D1::fcn()" << std::endl; return 0; }
	virtual void f2() { std::cout << "D1::f2()" << std::endl; }
};

class D2 : public D1 {
public:
	int fcn(int);
	int fcn() override { std::cout << "D2::fcn()" << std::endl; return 0; }
	virtual void f2() override { std::cout << "D2::f2()" << std::endl; }
};

int main()
{
	Base bobj; 
	D1 d1obj;
	D2 d2obj;

	Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
	bp1->fcn();                         // 虚调用，运行时将调用Base::fcn()
	bp2->fcn();                         // 虚调用，运行时将调用D1::fcn()
	bp3->fcn();                         // 虚调用，运行时将调用D2::fcn()

	D1 *d1p = &d1obj;
	D2 *d2p = &d2obj;
	//bp2->f2();                             // 错误，Base没有成员f2
	d1p->f2();                            // 虚调用，运行时将调用D1::f2()
	d2p->f2();                            // 虚调用，运行时将调用D2::f2()


	return 0;
}