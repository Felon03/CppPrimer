/*��д�������������ַ������泣���������������һ����̬�����char�����С�
	��д�������������������׼��string����
*/
#include<iostream>
#include<string>
#include<cstring>

int main()
{
	const char *c1 = "Hello ";
	const char *c2 = "World";
	unsigned len = strlen(c1) + strlen(c2) + 1;
	char *r = new char[len]();
	// strcat_s() ���������ַ���
	// ��һ��������Ŀ���ַ���ָ�룬�ڶ����������ַ������ȣ���������Դ�ַ���ָ��
	strcat_s(r, len, c1);
	strcat_s(r, len, c2);
	std::cout << r << std::endl;

	const std::string s1 = "hello ";
	const std::string s2 = "world";
	auto s3 = s1 + s2;
	unsigned size = s3.size() + 1;
	char *rs = new char[size]();
	// strcpy_s()��Դ�ַ���������Ŀ���ַ���
	// ��һ��������Ŀ���ַ���ָ�룬�ڶ����������ַ������ȣ���������Դ�ַ���ָ��
	strcpy_s(rs, size, s3.c_str());
	std::cout << rs << std::endl;
	delete[] r, rs;
	return 0;
}