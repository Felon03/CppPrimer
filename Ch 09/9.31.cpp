/*使在第316页中删除偶数元素并复制奇数元素的程序用于list或forward_list*/
#include<iostream>
#include<list>
#include<forward_list>

using namespace std;

int main()
{
	list<int> lst = { 0,1,2,3,4,5,6,7,8,9 };
	forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };

	// list version
	auto curr_lst = lst.begin();
	while (curr_lst != lst.end())
	{
		if (*curr_lst % 2)
		{
			//auto prev = curr_lst;
			//++curr_lst;
			curr_lst = lst.insert(curr_lst, *curr_lst);
			++curr_lst;
			++curr_lst;
			//advance(curr_lst, 2);
		}
		else
			curr_lst = lst.erase(curr_lst);
	}

	for (const auto &x : lst)
		cout << x << " ";
	cout << endl;

	// forward_list version
	auto prev = flst.before_begin(), curr = flst.begin();
	while (curr != flst.end())
	{
		if (*curr % 2)
		{
			prev = curr;
			curr = flst.insert_after(curr, *curr);
			++curr, ++prev;
			//another solution
		   //curr = flst.insert_after(prev, *curr);
		   //advance(curr, 2);
		   //advance(prev, 2);
		}
		else
		{
			curr = flst.erase_after(prev);
		}
	}

	for (const auto &x : flst)
		cout << x << " ";
	cout << endl;

	return 0;
}