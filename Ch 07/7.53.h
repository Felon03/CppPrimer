/*定义自己的Debug*/
#pragma once
class Debug
{
public:
	constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}

	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { other = b; }

private:
	bool hw;				// hardware error
	bool io;					// I/O error
	bool other;			// the others

};
