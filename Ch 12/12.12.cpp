/* p��q�Ķ������£����ڽ������Ķ�process��ÿ�����ã�
	����Ϸ�������������ʲô��������Ϸ������ʹ���ԭ��
*/
#include<iostream>
#include<memory>

using namespace std;

void process(shared_ptr<int> ptr)
{
	cout << "inside process funtion: " << ptr.use_count() << endl;
}

int main()
{
	auto p = new int();
	auto sp = make_shared<int>();

	// �Ϸ�������sp��process()�����н��д���
	// ��process���еĹ�����sp�����ü���Ϊ2
	//process(sp);

	// �Ƿ������ܽ�һ������ָ����ʽת��Ϊһ������ָ��
	//process(new int());

	// �Ƿ������ܽ�һ������ָ����ʽת��Ϊһ������ָ��
	//process(p);

	// �Ϸ��������Ƽ���ô����
	// process()��������ͷ�p��ָ����ڴ棬
	// ��main��delete p�ᷢ�����󣬼������ͷ�
	//process(shared_ptr<int>(p));

	return 0;
}