/*��������������������vector���󣬱�дһ�γ��򣬼�������һ��vector�����Ƿ�����һ����ǰ׺*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> arrA{ 0,1,1,2 }, arrB{ 0,1,1,2,3,5,8 };
	vector<int> arrMin;
	vector<int> arrMax;

	/*����һ��ͨ��forѭ�����ж�*/
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

	/*����������ȡ����Ϊ�ϴ�vector�г���Ϊ��Сvector�Ĳ��֣�ֱ�ӱȽ�����vector*/
	vector<int> arrCpy;
	arrCpy.assign(arrMax.begin(), arrMax.begin() + arrMin.size());
	if (arrMin == arrCpy)
		cout << "True" << endl;
	else
		cout << "False" << endl;

	return 0;
}