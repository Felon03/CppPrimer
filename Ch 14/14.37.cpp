/* ��дһ��������������ֵ�Ƿ���ȡ�ʹ�øĶ��󼰱�׼���㷨��д����
	�����滻ĳ�����о��и���ֵ������ʵ��
*/
#include<iostream>
#include<string>
#include<algorithm>

class IsEqual {
public:
	IsEqual(char ch) : c(ch) {}

	bool operator() (char rhs) const
	{
		return c == rhs;
	}

private:
	char c;
};

int main()
{
	std::string s{ "hello world nice to meet you" };
	std::replace_if(s.begin(), s.end(), IsEqual(' '), ',');

	for (const auto &x : s)
		std::cout << x;
	std::cout << std::endl;
}