#include "13.28.h"

TreeNode & TreeNode::operator=(const TreeNode & rhs)
{
	// TODO: �ڴ˴����� return ���
	++*rhs.count;										// �����Ҳ������������ü���
	if (--*count == 0)								// �ݼ�����������ü���
	{																// �ͷű��������ĳ�Ա
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
	value = rhs.value;								// �����ݴ�rhs������������
	count = rhs.count;
	left = rhs.left;
	right = rhs.right;
	return *this;										// ���ر�����
}

BinStrTree & BinStrTree::operator=(const BinStrTree & rhs)
{
	// TODO: �ڴ˴����� return ���
	TreeNode *new_root = new TreeNode(*rhs.root);
	delete root;
	root = new_root;
	return *this;
}
