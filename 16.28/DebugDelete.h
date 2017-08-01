#pragma once
/*
    16.28 编写你自己版本的shared_ptr和unique_ptr
*/

//
// DebugDelete 函数对象类，对给定的指针执行delete
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
