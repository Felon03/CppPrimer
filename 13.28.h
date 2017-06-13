#pragma once
/* ����������࣬Ϊ��ʵ��һ��Ĭ�Ϲ��캯���ͱ�Ҫ�Ŀ������Ƴ�Ա*/
#include<string>

class TreeNode {
public:
	TreeNode()
		: value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}
	// �������캯��
	TreeNode(const TreeNode &rhs)
		: value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right)
	{
		++*count;
	}
	// ������ֵ����
	TreeNode& operator=(const TreeNode &rhs);

	~TreeNode()
	{
		if (--*count == 0)
		{
			if (left)
			{
				delete left;
				left = nullptr;
			}
			if (right)
			{
				delete right;
				right = nullptr;
			}
			delete count;
			count = nullptr;
		}
	}

private:
	std::string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree {
public:
	BinStrTree() : root(new TreeNode()) {}
	// �������캯��
	BinStrTree(const BinStrTree &rhs)
		: root(new TreeNode(*rhs.root)) {}
	// ������ֵ����
	BinStrTree& operator=(const BinStrTree &rhs);

	~BinStrTree()
	{
		delete root;
	}

private:
	TreeNode *root;
};