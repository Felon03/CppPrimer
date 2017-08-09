/*改写6.3.2节练习中使用递归输出vector内容的程序，使其有条件的输出与执行过程有关的信息
	例如，每次调用时输出vector对象的大小。分别在打开和关闭调试器的情况下编译并执行这个程序
*/
#include<iostream>
#include<vector>

using namespace std;

//#define NDEBUG

void print(vector<int> &vec)
{
#ifdef NDEBUG
	cout << "vector size: " << vec.size() << endl;
#endif // NDEBUG
	if (!vec.empty())
	{
		auto tmp = vec.back();
		vec.pop_back();
		print(vec);
		cout << tmp << " ";
	}
}

int main()
{
	vector<int> vec  { 1,2,3,4,5,6,7,8,9,10 };
	print(vec);
	cout << endl;

	return 0;
}