#pragma once
/* 为Message类添加一个移动构造函数和一个移动赋值运算符*/
#include<set>
#include<string>

class Folder;

class Message {
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	friend class Folder;
public:
	explicit Message(const std::string &str="") :contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	// 移动构造函数
	Message(Message&&);
	// 移动赋值运算符
	Message& operator=(Message&&);
	~Message();
	
	void save(Folder&);
	void remove(Folder&);
	void print();
	
private:
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void move_Folders(Message*);

	void addFldr(Folder *f) { folders.insert(f); }
	void remFldr(Folder *f) { folders.erase(f); }

private:
	std::string contents;
	std::set<Folder*> folders;
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
	// 移动构造函数
	Folder(Folder&&);
	// 移动赋值运算符
	Folder& operator=(Folder&&);
	~Folder();

	void print();

private:
	void add_to_Message(const Folder&);
	void remove_from_Message();
	void move_Messages(Folder*);

	void addMsg(Message *m) { msgs.insert(m); }
	void remMsg(Message *m) { msgs.erase(m); }

private:
	std::set<Message*> msgs;
};

void swap(Folder&, Folder&);