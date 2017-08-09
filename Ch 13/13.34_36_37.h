#pragma once
/* ��дMessage��Folder��*/
#include<string>
#include<set>

class Folder;

class Message {
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	friend class Folder;
public:
	explicit Message(const std::string &str = "") : contents(str) {}

	Message(const Message&);	                 // �������캯��
	Message& operator=(const Message&);    // ������ֵ�����
	~Message();                                                // ��������

	// �Ӹ���Folder���������/ɾ����Message
	void save(Folder&);
	void remove(Folder&);

	// ���Message����
	void print();

private:
	std::string contents;				// ʵ����Ϣ�ı�
	std::set<Folder*> folders;	// ������Message��Folder

	// �������캯����������ֵ�����������������ʹ�õĹ��ߺ���
	// ����Message��ӵ�ָ�������Folder��
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
	std::set<Message*> msgs;       // ����Message�ļ���

	void add_to_Messages(const Folder&);
	void remove_from_Messages();

	void addMsg(Message *m) { msgs.insert(m); }
	void remMsg(Message *m) { msgs.erase(m); }
};
void swap(Folder&, Folder&);