/* ���ִ������Ĵ��룬�ᷢ��ʲô*/
#include<iostream>
#include<memory>

int main()
{
	auto sp = std::make_shared<int>();
	auto p = sp.get();
	delete p;

	// delete p���ͷ�spָ����ڴ�
	// main()��������ʱ���Զ��ͷ�����ָ��sp��
	// ��ɶ����ͷ�
	return 0;
}