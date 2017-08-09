#pragma once
/* 编写Message和Folder类*/
#include<string>
#include<set>

class Folder;

class Message {
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	friend class Folder;
public:
	explicit Message(const std::string &str = "") : contents(str) {}

	Message(const Message&);	                 // 拷贝构造函数
	Message& operator=(const Message&);    // 拷贝赋值运算符
	~Message();                                                // 析构函数

	// 从给定Folder集合中添加/删除本Message
	void save(Folder&);
	void remove(Folder&);

	// 输出Message内容
	void print();

private:
	std::string contents;				// 实际消息文本
	std::set<Folder*> folders;	// 包含本Message的Folder

	// 拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
	// 将本Message添加到指向参数的Folder中
	void add_to_Folders(const Message&);
	void remove_from_Folders();

	void addFldr(Folder *f) { folders.insert(f); }
	void remFldr(Folder *f) { folders.erase(f); }
};

void swap(Message&, Message&);

class Folder {
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	friend class Message;
public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();

	void print();

private:
	std::set<Message*> msgs;       // 包含Message的集合

	void add_to_Messages(const Folder&);
	void remove_from_Messages();

	void addMsg(Message *m) { msgs.insert(m); }
	void remMsg(Message *m) { msgs.erase(m); }
};
void swap(Folder&, Folder&);