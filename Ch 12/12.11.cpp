/*�����������������process���ᷢ��ʲô��*/

// ������p������ʱ��pָ����ڴ�ᱻ�ڶ���delete

#include<iostream>
#include<memory>

using namespace std;

void process(shared_ptr<int> ptr)
{
	cout << "inside the process function: " << ptr.use_count() << endl;
}

int main()
{
	shared_ptr<int> p(new int(42));
	process(shared_ptr<int>(p.get()));
	// shared_ptr<int>(p.get())����һ����ʱshared_ptr����
	// �����䴫��process�����������ʱ������qָ����ͬ�ڴ�
	// ������p�Ŀ����������������ġ������ü���Ϊ1��
	// ���˳�processʱ��ʱpָ����ڴ��Ѿ����ͷ�
	// ��main��������ʱ�ͷ�p�ͻ����

	return 0;
}