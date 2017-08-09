#include"13.49_Message.h"

int main()
{
	Message firstMail("Hello");
	Message signInMail("Welcome to cppprimer");
	Folder mailBox;

	//swap(firstMail, signInMail);

	firstMail.save(mailBox);
	signInMail.save(mailBox);
	mailBox.print();

	//firstMail = std::move(signInMail);
	signInMail = std::move(firstMail);
	mailBox.print();
	return 0;
}