/* 用allocator重写第427页中的程序*/
#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include<stack>

using namespace std;

void print_string_allocator(int n)
{
	allocator<string> alloc;
	vector<string> svec;
	stack<string> sstack;
	string str;
	auto const p = alloc.allocate(n);
	auto q = p;
	while (cin >> str && q != p + n)
		alloc.construct(q++, str);
	const size_t size = q - p;
	cout << "The difference between p and q: " << size << endl;
	cout << "Out put strings: " << endl;
	while (q != p)
	{
		sstack.push(*--q);
		alloc.destroy(q);
	}
	alloc.deallocate(p, n);
	
	while (!sstack.empty())
	{
		cout << sstack.top() << endl;
		sstack.pop();
	}
		
}

int main()
{
	int size = 0;
	cout << "Please enter the number of strings you want entered: ";
	cin >> size;
	cout << "Input the strings:" << endl;
	print_string_allocator(size);

	return 0;
}
