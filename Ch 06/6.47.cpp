/*��д6.3.2����ϰ��ʹ�õݹ����vector���ݵĳ���ʹ���������������ִ�й����йص���Ϣ
	���磬ÿ�ε���ʱ���vector����Ĵ�С���ֱ��ڴ򿪺͹رյ�����������±��벢ִ���������
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