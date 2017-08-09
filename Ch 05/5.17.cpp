/*假设有两个包含整数的vector对象，编写一段程序，检验其中一个vector对象是否是另一个的前缀*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> arrA{ 0,1,1,2 }, arrB{ 0,1,1,2,3,5,8 };
	vector<int> arrMin;
	vector<int> arrMax;

	/*方法一，通过for循环来判断*/
	if (arrA.size() > arrB.size())
	{
		arrMax = arrA;
		arrMin = arrB;
	}
	else
	{
		arrMax = arrB;
		arrMin = arrA;
	}

	for (auto begMin = arrMin.begin(), begMax = arrMax.begin();
		begMin != arrMin.end(); ++begMin, ++begMax)
	{
		if (*begMin == *begMax)
		{
			if (begMin == arrMin.end() - 1)
				cout << "True" << endl;
			else
				continue;
		}
		else
		{
			cout << "False" << endl;
			break;
		}

	}

	/*方法二，截取长度为较大vector中长度为较小vector的部分，直接比较两个vector*/
	vector<int> arrCpy;
	arrCpy.assign(arrMax.begin(), arrMax.begin() + arrMin.size());
	if (arrMin == arrCpy)
		cout << "True" << endl;
	else
		cout << "False" << endl;

	return 0;
}