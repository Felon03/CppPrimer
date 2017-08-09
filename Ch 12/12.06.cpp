/* 编写函数，返回一个动态分配的int的vector。将此vector传递给另一个函数，
	这个函数读取标准输入，将读入的值白存在vector元素中。再将vector传递给
	另一个函数，打印读入的值。记得在恰当的时刻delete vector。
*/
#include<iostream>
#include<vector>

using namespace std;

vector<int>* generate_vector()
{
	vector<int> *v = new vector<int>();
	return v;
}

void write_to_vector(vector<int> *v)
{
	int i;
	cout << "please enter Integer:" << endl;
	while (cin >> i && i != -1) v->push_back(i);
}

void print_vector(vector<int> *v)
{
	for (const auto &x : *v)
		cout << x << " ";
	cout << endl;
}

int main()
{
	// vector<int>* v = generate_vector();
	auto v = generate_vector();
	write_to_vector(v);
	print_vector(v);

	delete v;

	return 0;
}