#pragma once
/*
    16.28 ��д���Լ��汾��shared_ptr��unique_ptr
*/

//
// DebugDelete ���������࣬�Ը�����ָ��ִ��delete
//

#include <iostream>
class DebugDelete {
public:
	DebugDelete(std::ostream &s =  std::cerr) : os(s) {}
	template<typename T> void operator()(T* p) const
	{
		os << "deleting ptr" << std::endl;
		delete p;
	}

private:
	std::ostream &os;
};
