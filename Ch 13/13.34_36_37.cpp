#include "13.34_36_37.h"
#include<iostream>

Message::Message(const Message &m)
	: contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

Message & Message::operator=(const Message &rhs)
{
	// TODO: �ڴ˴����� return ���
	// ��ͨ��ɾ��ָ���ٲ��������������Ը�ֵ���
	remove_from_Folders();               // ��������Folder
	contents = rhs.contents;              // ��rhs������Ϣ����
	folders = rhs.folders;                     // ��rhs����Folderָ��
	add_to_Folders(rhs);                     // ����Message��ӵ���ЩFolder��
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder &f)
{
	folders.insert(&f);       // ������Folder��ӵ����ǵ�Folder�б���
	f.addMsg(this);            // ����Message��ӵ�f��Message������
}

void Message::remove(Folder &f)
{
	folders.erase(&f);       // ������Folder�����ǵ�Folder�б���ɾ��
	f.remMsg(this);            // ����Message��f��Message������ɾ��
}

void Message::print()
{
	std::cout << contents << std::endl;
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)         // ��ÿ������m��Folder
		f->addMsg(this);                // ���Folder���һ��ָ��Message��ָ��
}

void Message::remove_from_Folders()
{
	for (auto f : folders)          // ��folders��ÿ��ָ��
		f->remMsg(this);            // �Ӹ�Folder��ɾ����Message
}

void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	// ��ÿ����Ϣ��ָ�����ԭ������Folder��ɾ��
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	// ����contents��Folderָ��set
	swap(lhs.folders, rhs.folders);          // ʹ��swap(set&, set&)
	swap(lhs.contents, rhs.contents);   // ʹ��swap(string&, string&)
	// ��ÿ��Message��ָ����ӵ�������Folder��
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

// Folder��

Folder::Folder(const Folder &f)
	: msgs(f.msgs)
{
	add_to_Messages(f);
}

Folder & Folder::operator=(const Folder &rhs)
{
	// TODO: �ڴ˴����� return ���
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

