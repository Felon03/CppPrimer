/*��д����̽������ı�׼��ʵ���У�vector�����������*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> ivec;
	cout << " ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	// ���Ԫ��
	for (auto ix = 0; ix != 24; ++ix)
		ivec.push_back(ix);
	cout << " ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	cout << " ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	// �ڲ���һ��Ԫ�أ�size����capacity����ʱcapacityӦ������
	ivec.push_back(100);
	cout << " ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	// ��capacity�����趨Ϊ50
	ivec.reserve(50);
	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	cout << " ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	ivec.push_back(100);
	cout << " ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	return 0;
}