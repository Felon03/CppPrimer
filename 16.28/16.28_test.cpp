/*
    16.28  编写你自己的shared_ptr和unique_ptr
*/
#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include "DebugDelete.h"
#include "shared_pointer.h"
#include "unique_pointer.h"

int main()
{
	std::vector<unique_pointer<int>> v;
	shared_pointer<int> s = shared_pointer<int>(new int(1));
	auto s1 = s;
	std::cout << s.use_count() << std::endl;
	auto s2 = s1;
	std::cout << s.use_count() << std::endl;
	v.reserve(10);
	for (int i = 0; i != 10; ++i)
		v.push_back(unique_pointer<int>(new int(i)));
	for (auto &x : v)
		std::cout << *x << "\n";

	return 0;
}

// output:
/*
2
3
deleting ptr
deleting ptr
deleting ptr
deleting ptr
deleting ptr
deleting ptr
deleting ptr
deleting ptr
deleting ptr
deleting ptr
0
1
2
3
4
5
6
7
8
9
deleting ptr
deleting ptr
deleting ptr
deleting ptr
deleting ptr
deleting ptr
deleting ptr
deleting ptr
deleting ptr
deleting ptr
deleting ptr
*/