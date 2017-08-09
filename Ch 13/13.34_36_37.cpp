#include "13.34_36_37.h"
#include<iostream>

Message::Message(const Message &m)
	: contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

Message & Message::operator=(const Message &rhs)
{
	// TODO: 在此处插入 return 语句
	// 先通过删除指针再插入它们来处理自赋值情况
	remove_from_Folders();               // 更新已有Folder
	contents = rhs.contents;              // 从rhs拷贝消息内容
	folders = rhs.folders;                     // 从rhs拷贝Folder指针
	add_to_Folders(rhs);                     // 将本Message添加到那些Folder中
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder &f)
{
	folders.insert(&f);       // 将给定Folder添加到我们的Folder列表中
	f.addMsg(this);            // 将本Message添加到f的Message集合中
}

void Message::remove(Folder &f)
{
	folders.erase(&f);       // 将给定Folder从我们的Folder列表中删除
	f.remMsg(this);            // 将本Message从f的Message集合中删除
}

void Message::print()
{
	std::cout << contents << std::endl;
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)         // 对每个包含m的Folder
		f->addMsg(this);                // 向该Folder添加一个指向本Message的指针
}

void Message::remove_from_Folders()
{
	for (auto f : folders)          // 对folders中每个指针
		f->remMsg(this);            // 从改Folder中删除本Message
}

void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	// 将每个消息的指针从它原来所在Folder中删除
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	// 交换contents和Folder指针set
	swap(lhs.folders, rhs.folders);          // 使用swap(set&, set&)
	swap(lhs.contents, rhs.contents);   // 使用swap(string&, string&)
	// 将每个Message的指针添加到它的新Folder中
	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
}

void swap(Folder &lhs, Folder &rhs)
{
	using std::swap;
	lhs.remove_from_Messages();
	rhs.remove_from_Messages();
	
	swap(lhs.msgs, rhs.msgs);

	lhs.add_to_Messages(lhs);
	rhs.add_to_Messages(rhs);

}

// Folder类

Folder::Folder(const Folder &f)
	: msgs(f.msgs)
{
	add_to_Messages(f);
}

Folder & Folder::operator=(const Folder &rhs)
{
	// TODO: 在此处插入 return 语句
	remove_from_Messages();
	msgs = rhs.msgs;
	add_to_Messages(rhs);
	return *this;
}

Folder::~Folder()
{
	remove_from_Messages();
}

void Folder::print()
{
	for (auto m : msgs)
		std::cout << m->contents << " ";
	std::cout << std::endl;
}

void Folder::add_to_Messages(const Folder &f)
{
	for (auto m : f.msgs)
		m->addFldr(this);
}

void Folder::remove_from_Messages()
{
	for (auto m : msgs)
		m->remFldr(this);
}

