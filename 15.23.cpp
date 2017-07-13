/* ����D1����Ҫ�������̳ж�����fcn��������Ӧ����ζ�������޸ģ�
	������޸�֮��fcnƥ����Base�еĶ��壬��ýڵĵ�����佫��ν�����
*/
#include<iostream>

class Base {
public:
	virtual int fcn() { std::cout << "Base::fcn()" << std::endl; return 0; }	
};

class D1 : public Base {
	// ����base��fcn
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
	bp1->fcn();                         // ����ã�����ʱ������Base::fcn()
	bp2->fcn();                         // ����ã�����ʱ������D1::fcn()
	bp3->fcn();                         // ����ã�����ʱ������D2::fcn()

	D1 *d1p = &d1obj;
	D2 *d2p = &d2obj;
	//bp2->f2();                             // ����Baseû�г�Աf2
	d1p->f2();                            // ����ã�����ʱ������D1::f2()
	d2p->f2();                            // ����ã�����ʱ������D2::f2()


	return 0;
}