/*�ٶ���һ����ΪNoDefault���࣬����һ������int�Ĺ��캯��������û��Ĭ�Ϲ��캯����������C��C��һ��NoDefault���͵ĳ�Ա������C��Ĭ�Ϲ��캯��*/
#include<iostream>
#include<vector>

using namespace std;

class NoDefault
{
public:
	NoDefault(int i) {}
};

class C
{
private:
	NoDefault def;

public:
	C() : def(0) {}
};

int main()
{
	C c;
	//vector<NoDefault> vec(10);		// ���Ϸ���NoDefaultû��Ĭ�ϵĹ��캯��
	vector<C> vec(10);							// �Ϸ���C��Ĭ�Ϲ��캯��

	return 0;
}