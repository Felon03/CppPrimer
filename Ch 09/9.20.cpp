/*编写程序，从一个list<int>拷贝元素到两个deque中。
值为偶数的所有元素都拷贝到一个deque中，而奇数值元素都拷贝到另一个deque中
*/
#include<iostream>
#include<list>
#include<deque>

using namespace std;

int main()
{
	list<int> myList{ 1,2,3,4,5,6,7,8,9,10 };
	deque<int> oddDeq, evenDeq;
	
	for (auto const &x : myList)
	{
		//x % 2 == 0 ? evenDeq.push_back(x) : oddDeq.push_back(x);
		(x % 2 == 0 ? evenDeq : oddDeq).push_back(x);		// 高仿 :D
	}
	// github上的一个方法
	//for (auto i : myList)(i & 0x1 ? oddDeq : evenDeq).push_back(i);

	for (auto const &x : oddDeq)
		cout << x << " ";
	cout << endl;

	for (auto const &x : evenDeq)
		cout << x << " ";
	cout << endl;

	return 0;
}