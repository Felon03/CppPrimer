/*��д����������һ��istream&����������ֵ����Ҳ��istream&��
�˺�����Ӹ������ж�ȡ����ֱ�������ļ�������ʶʱֹͣ��
������ȡ�����ݴ�ӡ�ڱ�׼����ϡ������Щ������ż���ڷ�����֮ǰ���������и�λ��ʹ�䴦����Ч״̬
*/
#include<iostream>
#include<string>

using namespace std;

istream &read(istream& is)
{
	string buf;
	while (is>>buf)
		cout << buf << endl;
	is.clear();
	return is;
}

int main()
{
	return 0;
}