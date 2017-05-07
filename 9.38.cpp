/*编写程序，探究在你的标准库实现中，vector是如何增长的*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> ivec;
	cout << " ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	// 添加元素
	for (auto ix = 0; ix != 24; ++ix)
		ivec.push_back(ix);
	cout << " ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	cout << " ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	// 在插入一个元素，size超过capacity，此时capacity应该增大
	ivec.push_back(100);
	cout << " ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	// 将capacity至少设定为50
	ivec.reserve(50);
	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	cout << " ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	ivec.push_back(100);
	cout << " ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	return 0;
}