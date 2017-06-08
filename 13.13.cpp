/*��⿽�����Ƴ�Ա�͹��캯����һ���÷����Ƕ���һ���򵥵��࣬
	Ϊ���ඨ����Щ��Ա��ÿ����Ա����ӡ���Լ������֣�

	struct X {
		X() { std::cout << "X()" << std::endl; }
		X(const X&) { std::cout<< "X(const X&)" << std::endl; }
	};
	��X��ӿ�����ֵ���������������������дһ�������Բ�ͬ�ķ�ʽʹ��X�Ķ���
	��������Ϊ�����ú����ò������ݣ���̬�������ǣ������Ǵ���������У�����
	���ࡣ�۲����������ָ�������������ʲôʱ���ʹ�ÿ������Ƴ�Ա���Լ�
	Ϊʲô��ʹ�����ǡ�����۲�������ʱ����ס�����������Թ��Կ������캯����
	���á�
*/

#include<iostream>
#include<vector>

class X {
public:
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X& operator= (const X &x)
	{
		std::cout << "X& operator=(const X &x)" << std::endl;
		return *this;
	}

	~X()
	{
		std::cout << "~X()" << std::endl;
	}
};

void f(const X&lx, X rx)
{
	std::vector<X> vec;
	vec.push_back(lx);
	vec.push_back(rx);
}

int main()
{
	X *x = new X;
	f(*x, *x);
	delete	x;

	return 0;
}