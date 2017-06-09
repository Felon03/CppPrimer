/*��⿽�����Ƴ�Ա�͹��캯����һ���÷����Ƕ���һ���򵥵��࣬
	Ϊ���ඨ����Щ��Ա��ÿ����Ա����ӡ���Լ������֣�

	struct X {
		X() { std::cout << "X()" << std::endl; }
		X(const X&) { std::cout<< "X(const X&)" << std::endl; }
	};
	��X��ӿ�����ֵ���������������������дһ�������Բ�ͬ�ķ�ʽʹ��X�Ķ���
	��������Ϊ�����ú����ò������ݣ���̬�������ǣ������Ǵ���������У�����
	���ࡣ�۲����������ָ����ȷ�������ʲôʱ���ʹ�ÿ������Ƴ�Ա���Լ�
	Ϊʲô��ʹ�����ǡ�����۲�������ʱ����ס�����������Թ��Կ������캯����
	���á�
*/

#include<iostream>
#include<vector>

class X {
public:
	// ���캯��
	X() { std::cout << "X()" << std::endl; }
	// �������캯��
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	// ������ֵ�����
	X& operator= (const X &x)
	{
		std::cout << "X& operator=(const X &x)" << std::endl;
		return *this;
	}
	// ��������
	~X()
	{
		std::cout << "~X()" << std::endl;
	}
};

void f(const X &lx, X rx)
{
	std::vector<X> vec;
	vec.reserve(2);		
	vec.push_back(lx);
	//std::cout << "about to do push_back(bx)" <<std::endl;
	vec.push_back(rx);
	// When second element is added to the vector(the vec.push_back(rx);)
	// a resize of the vector's underlying stroage is done and the single element
	// already in the vector is copied to the new storage.
	// ref:https://stackoverflow.com/questions/32240542/the-c-primer-exercise-13-13-about-the-constructor
	// ��vec����ڶ���Ԫ��ʱ��vec��Ҫ���·����ַ����û��reserve(2)������£�
	// ����ǰvec���Ѿ�����һ��Ԫ�أ���Ҫ���俽�����µĵ�ַ����ʱ�����һ��
	// �������캯��X(const X&);
	//std::cout << "done push_back(bx)" << std::endl;
}

int main()
{
	X *x = new X;
	f(*x, *x);
	delete	x;

	return 0;
}