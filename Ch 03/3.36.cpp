/*编写一段程序，比较两个数组是否相等。再写一段程序，比较两个vector对象是否相等*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	constexpr size_t sz = 5;
	int a[sz], b[sz];
	for (size_t i = 0; i < sz; i++)
	{
		a[i] = i;
		b[i] = i;
	}
	if (sizeof(a) != sizeof(b))
		cout << "Array a not equals b" << endl;
	else
	{
		int cnt = 0;
		for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		{
			if (a[i] == b[i])
				cnt++;
			else
				break;
		}
		if (cnt == sizeof(a) / sizeof(a[0]))
			cout << "Arrays are equal" << endl;
		else
			cout << "Arrays are not equal" << endl;
	}

	vector<int> va;
	vector<int> vb;
	int x;
	while (cin>>x)
	{
		va.push_back(x);
		//vb.push_back(x);
		vb.push_back(x + 1);
	}

	if (va.size() != vb.size())
		cout << "vectors are not equal" << endl;
	else
	{
		if (va == vb)
			cout << "vectors are equal" << endl;
		else
			cout << "vectors are not equal" << endl;
	}


	return 0;
}