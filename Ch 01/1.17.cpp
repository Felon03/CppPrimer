#include<iostream>
using namespace std;

int main8()
{
	// currVal 表示当前统计的数，将读入的新值存入val
	int currVal = 0, val = 0;
	// 读取第一个数，并确保确实有数据可以处理
	if (cin>>currVal)
	{
		int cnt = 1;				// 保存正在处理的当前值的个数
		while (cin>>val)
		{
			if (val == currVal)
			{
				++cnt;
			}
			else
			{
				cout << currVal << " occurs " << cnt << " times." << endl;
				currVal = val;		// 记录新值
				cnt = 1;					// 重置计数器
			}
		}	// while
		// 记住打印文件中最后一个值的个数
		cout << currVal << " occurs " << cnt << " times." << endl;
	}	// if
	return 0;
}