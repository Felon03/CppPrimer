/* ��д����������һ����̬�����int��vector������vector���ݸ���һ��������
	���������ȡ��׼���룬�������ֵ�״���vectorԪ���С��ٽ�vector���ݸ�
	��һ����������ӡ�����ֵ���ǵ���ǡ����ʱ��delete vector��
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