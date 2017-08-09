#pragma once
/* 给定下面的类，为其实现一个默认构造函数和必要的拷贝控制成员*/
#include<string>

class TreeNode {
public:
	TreeNode()
		: value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}
	// 拷贝构造函数
	TreeNode(const TreeNode &rhs)
		: value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right)
	{
		++*count;
	}
	// 拷贝赋值函数
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
	// 拷贝构造函数
	BinStrTree(const BinStrTree &rhs)
		: root(new TreeNode(*rhs.root)) {}
	// 拷贝赋值函数
	BinStrTree& operator=(const BinStrTree &rhs);

	~BinStrTree()
	{
		delete root;
	}

private:
	TreeNode *root;
};