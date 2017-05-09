/*使用stack处理括号化的表达式。当你看到一个左括号，将其记录下来。
当你在一个左括号之后看到一个右括号，从stack中pop对象，直到遇到左括号
将左括号也一起弹出栈。然后将一个值（括号内的运算结果）push到栈中，表示括号化
的（子）表达式已经处理完毕，被其运算结果所替代*/
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
		if (stk.top() == '(') ++count;			// 遇到左括号 计数器加一
		if (count&&stk.top() == ')')				// 计数器不为零且遇到了右括号
		{
			while (stk.top() != '(')					// 出栈直到栈顶元素为左括号
				stk.pop();
			stk.pop();											// 将左括号出栈
			stk.push(repl);								// 将repl压入栈内，表示一个括号表达式处理完毕
			--count;											// 处理完毕，计数器减一
		}
	}

	// Test
	string output;
	for (; !stk.empty(); stk.pop()) output.insert(output.begin(), stk.top());
	cout << output << endl;
}