#pragma once
/* ��д���Լ��汾��StrVec�������Լ��汾��reserve��capacity��resize*/
#include<string>
#include<memory>

// ��vector���ڴ������Եļ�ʵ��
class StrVec {
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

	StrVec(const StrVec&);                                   // �������캯��
	StrVec& operator=(const StrVec&);          // ������ֵ�����
	~StrVec();                                                             // ��������

	void push_back(const std::string&);           // ����Ԫ��
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
	//todo: reverse��resize
	void reverse(size_t newcap);
	void resize(size_t count);
	void resize(size_t count, const std::string&);

private:
	// �����Ԫ�صĺ���ʹ��
	void chk_n_alloc()
	{
		if (size() == capacity())
			reallocate();
	}
	// ���ߺ��������������캯������ֵ���������������ʹ��
	std::pair<std::string*, std::string*> alloc_n_copy
	(const std::string*, const std::string*);
	void free();                                           // ����Ԫ�ز��ͷ��ڴ�
	void reallocate();                              // ��ø����ڴ沢��������Ԫ��
	void alloc_n_move(size_t newcap); // �ƶ������ǿ���ԭ����Ԫ��
	std::string *elements;                     // ָ��������Ԫ�ص�ָ��
	std::string *first_free;                     // ָ�������һ������Ԫ�ص�ָ��
	std::string *cap;                                 // ָ������β��λ�õ�ָ��
	static std::allocator<std::string> alloc;           // ����Ԫ��
};