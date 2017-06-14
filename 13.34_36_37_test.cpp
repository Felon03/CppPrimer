#include"13.34_36_37.h"

using namespace std;

int main()
{
	Message firstMail("hello");
	Message signInMail("Welcome to cppprimer");
	Message testMail("Test");
	Folder mailBox, mailBox1;

	firstMail.print();                             // hello
	firstMail.save(mailBox);             // 保存到folder中
	mailBox.print();                             // hello

	signInMail.print();                        // Welcome to cppprimer
	signInMail.save(mailBox);         // 保存到folder中
	mailBox.print();                            // Welcome to cppprimer hello

	firstMail.save(mailBox1);          // 保存到新的folder
	signInMail.save(mailBox1);       // 保存到新的folder
	mailBox1.print();                          // Welcome to cppprimer hello
	
	firstMail = firstMail;                    // 测试自赋值
	firstMail.print();                           // hello
	mailBox.print();                            // Welcome to cppprimer hello

	testMail.save(mailBox);
	firstMail = testMail;                    // 将testMail的内容赋给firstMail
	firstMail.print();                            // Test
	mailBox.print();                             // Welcome to cppprimer Test

	firstMail.remove(mailBox);       // 从mailBox中删除firstMail
	mailBox.print();                             // Welcome to cppprimer

	return 0;
}