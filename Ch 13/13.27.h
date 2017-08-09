#pragma once
/* ����ʹ�����ü����汾��HasPtr*/
#include<string>

class HasPtr {
public:
	// ���캯�������µ�string���µļ�����������������Ϊ1
	HasPtr(const std::string &s = std::string())
		: ps(new std::string(s)), i(0), use(new std::size_t(1)) {}

	// �������캯�����������������ݳ�Ա��������������
	HasPtr(const HasPtr &rhs) : ps(rhs.ps), i(rhs.i), use(rhs.use)
	{
		++*use;
	}

	HasPtr& operator=(const HasPtr &rhs)
	{
		++*rhs.use;				// �����Ҳ��������������ü���
		if (--*use == 0)			// Ȼ��ݼ�����������ü���
		{			
			delete ps;			// ���û�������û�
			delete use;			// �ͷű��������ĳ�Ա
		}
		ps = rhs.ps;				// �����ݴ�rhs������������
		i = rhs.i;
		use = rhs.use;
		return *this;			// ���ر�����
	}
	~HasPtr()
	{
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
	}

private:
	std::string *ps;
	int i;
	std::size_t *use;			// ������¼�ж��ٸ�������*ps��Ա
};