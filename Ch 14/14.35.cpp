/* ��дһ��������PrintString���࣬�����istream�ж�ȡһ�����룬
	Ȼ�󷵻�һ����ʾ�����������ݵ�string�������ȡʧ�ܣ����ؿ�string
*/
#include<string>
#include<iostream>

class ReadString {
public:
	ReadString(std::istream &in = std::cin) : is(in) {}
	std::string operator() () const
	{
		std::string str = "";
		std::getline(is, str);
		return is ? str : std::string();
	}

private:
	std::istream &is;    // ���ڶ�ȡ����
};

int main()
{
	ReadString read;
	std::string mystr = read();
	std::cout << mystr << std::endl;

	return 0;
}