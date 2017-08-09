/* 
    16.47 ��д���Լ��汾�ķ�ת������ͨ�����ý�����ֵ����ֵ���ò����ĺ�����������
*/

#include<iostream>
#include<memory>

void func_lvalue(int &v1, int &v2)
{
	std::cout << ++v1 << " " << ++v2 << std::endl;
}

void func_rvalue(int &&v1, int &&v2)
{
	std::allocator<int> alloc;
	int* data(alloc.allocate(3));

	alloc.construct(data, v1);
	alloc.construct(data + 1, 0);
	alloc.construct(data + 2, v2);

	// print
	for (auto p = data; p != data + 3; ++p)
		std::cout << *p << " ";
	std::cout << "\n";

	// deallocate
	for (auto p = data + 3; p != data;)
		alloc.destroy(--p);
	alloc.deallocate(data, 3);
}

// template
template<typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

// main func
int main()
{
	// test func_lvalue
	int v1 = 10, v2 = 15;
	flip(func_lvalue, v1, v2);

	// test func_rvalue
	flip(func_rvalue, 10, 15);
	
	return 0;
}