#pragma once
/* 验证15.18，15.19*/

class Base {
public:
	void pub_mem();
protected:
	int prot_mem;
private:
	char priv_mem;
};

class Pub_Derv : public Base {
	int f() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

class Priv_Derv : private Base {
	int f1() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

class Prot_Derv : protected Base {
	int f2() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv {
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : private Priv_Derv {
	//int use_base() { return prot_mem; }    // ERROR
	//void memfcn(Base &b) { b = *this; }   // ERROR Base不可访问
};

struct Derived_from_Protected : protected Prot_Derv {
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};