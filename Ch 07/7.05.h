/*��Person�����ṩһЩ����ʹ���ܹ�����������סַ*/
#pragma once
#include<string>
class Persion
{
	std::string name;			// ����
	std::string address;		// סַ

public:
	const std::string& getName() const { return name; }
	const std::string& getAddress() const { return address; }
};


// ��Щ�����Ƿ�Ӧ����const�أ����������
// Ӧ����const����Ϊ��ȡ���ֺͻ�ȡ��ַ����ֻ�Ƕ�ȡ��������ݣ����������޸�