#include "13.28.h"

TreeNode & TreeNode::operator=(const TreeNode & rhs)
{
	// TODO: 在此处插入 return 语句
	++*rhs.count;										// 递增右侧运算对象的引用计数
	if (--*count == 0)								// 递减本对象的引用计数
	{																// 释放本对象分配的成员
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
	value = rhs.value;								// 将数据从rhs拷贝到本对象
	count = rhs.count;
	left = rhs.left;
	right = rhs.right;
	return *this;										// 返回本对象
}

BinStrTree & BinStrTree::operator=(const BinStrTree & rhs)
{
	// TODO: 在此处插入 return 语句
	TreeNode *new_root = new TreeNode(*rhs.root);
	delete root;
	root = new_root;
	return *this;
}
