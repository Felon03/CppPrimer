#include"13.34_36_37.h"

using namespace std;

int main()
{
	Message firstMail("hello");
	Message signInMail("Welcome to cppprimer");
	Message testMail("Test");
	Folder mailBox, mailBox1;

	firstMail.print();                             // hello
	firstMail.save(mailBox);             // ���浽folder��
	mailBox.print();                             // hello

	signInMail.print();                        // Welcome to cppprimer
	signInMail.save(mailBox);         // ���浽folder��
	mailBox.print();                            // Welcome to cppprimer hello

	firstMail.save(mailBox1);          // ���浽�µ�folder
	signInMail.save(mailBox1);       // ���浽�µ�folder
	mailBox1.print();                          // Welcome to cppprimer hello
	
	firstMail = firstMail;                    // �����Ը�ֵ
	firstMail.print();                           // hello
	mailBox.print();                            // Welcome to cppprimer hello

	testMail.save(mailBox);
	firstMail = testMail;                    // ��testMail�����ݸ���firstMail
	firstMail.print();                            // Test
	mailBox.print();                             // Welcome to cppprimer Test

	firstMail.remove(mailBox);       // ��mailBox��ɾ��firstMail
	mailBox.print();                             // Welcome to cppprimer

	return 0;
}