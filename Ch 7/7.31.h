#pragma once
/*����һ����X��Y������X����һ��ָ��Y��ָ�룬��Y����һ������ΪX�Ķ���*/

class Y;

class X
{
	Y *y = nullptr;
};

class Y
{
	X x;
};