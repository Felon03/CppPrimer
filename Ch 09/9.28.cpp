/*编写函数，接受一个forward_list<string>和两个string共三个参数。
函数应在链表中查找第一个string,并将第二个string插入到紧接着第一个string之后的位置
若第一个string未在链表中，则将第二个string插到链表末尾
*/
#include<iostream>
#include<forward_list>
#include<string>

using namespace std;

void insert_str(forward_list<string> &flist, const string &s1, const string &s2)
{
	auto prev = flist.before_begin(), curr = flist.begin();
	bool flag = false;			// 标记flist中是否包含s1
	while (curr != flist.end())
	{
		if (*curr == s1)
		{
			prev = curr;		// prev保存当前的元素
			curr = flist.insert_after(curr, s2);		// curr指向新插入的元素
			flag = true;
		}
		else
		{
			prev = curr;
			++curr;
		}
	}
	if (!flag)
		curr = flist.insert_after(prev, s2);		// 如果flist中不含s1, 则此时curr指向flist.end(), 而指向最后一个元素的是prev
}

int main()
{
	forward_list<string> flist = { "hello", "world", "nice", "to", "meet", "you!" }, flist1 = { "a", "a","b","c","d" };
	string s1 = "world1", s2 = "guys";
	insert_str(flist, s1, s2);
	s1 = "a", s2 = "z";
	insert_str(flist1, s1, s2);

	for (const auto &x : flist)
		cout << x << " ";
	cout << endl;
	for (const auto &x : flist1)
		cout << x << " ";
	cout << endl;

	return 0;
}