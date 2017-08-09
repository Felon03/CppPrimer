/*在Person类中提供一些操作使其能够返回姓名和住址*/
#pragma once
#include<string>
class Persion
{
	std::string name;			// 姓名
	std::string address;		// 住址

public:
	const std::string& getName() const { return name; }
	const std::string& getAddress() const { return address; }
};


// 这些函数是否应该是const呢？请给出理由
// 应该是const，因为获取名字和获取地址函数只是读取对象的内容，并不对其修改