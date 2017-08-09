#pragma once
/* 编写DebugDelete*/
#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include <iostream>

class DebugDelete {
public:
	DebugDelete(std::ostream &s = std::cerr) : os(s) {}
	// 与任何函数模板相同，T的类型由编译器推断
	template<typename T> void operator() (T *p) const
	{
		os << "deleting unique_ptr" << std::endl;
		delete p;
	}
private:
	std::ostream &os;
};


#endif // !DEBUGDELETE_H
