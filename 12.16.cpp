/*  �������ͼ������ֵunique_ptr�����������������ܸ����������Ĵ�����Ϣ��
	��д�������ִ���ĳ��򣬹۲���������������ִ���	
*/
#include<iostream>
#include<memory>

int main()
{
	std::unique_ptr<int> p1(new int(42));
	// ����
	//std::unique_ptr<int> p2(p1);	// ����������ɾ���ĺ���
	std::unique_ptr<int> p3;
	// ��ֵ
	//p3 = p1;		// ����������ɾ���ĺ���
	std::cout << *p1 << std::endl;
	p1.reset();
	return 0;
}