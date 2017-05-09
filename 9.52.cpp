/*ʹ��stack�������Ż��ı��ʽ�����㿴��һ�������ţ������¼������
������һ��������֮�󿴵�һ�������ţ���stack��pop����ֱ������������
��������Ҳһ�𵯳�ջ��Ȼ��һ��ֵ�������ڵ���������push��ջ�У���ʾ���Ż�
�ģ��ӣ����ʽ�Ѿ�������ϣ����������������*/
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	auto &expr = "This is a (C++ program(Hello world!)) and a (awesome) test.";
	auto repl = '*';
	auto count = 0;

	stack<char> stk;
	for (const auto &c : expr)
	{
		stk.push(c);
		if (stk.top() == '(') ++count;			// ���������� ��������һ
		if (count&&stk.top() == ')')				// ��������Ϊ����������������
		{
			while (stk.top() != '(')					// ��ջֱ��ջ��Ԫ��Ϊ������
				stk.pop();
			stk.pop();											// �������ų�ջ
			stk.push(repl);								// ��replѹ��ջ�ڣ���ʾһ�����ű��ʽ�������
			--count;											// ������ϣ���������һ
		}
	}

	// Test
	string output;
	for (; !stk.empty(); stk.pop()) output.insert(output.begin(), stk.top());
	cout << output << endl;
}