/* 12.17 下面的unique_ptr声明中，哪些是合法的，哪些可能导致后续的程序错误？
	解释每个错误的问题在哪里。	
*/

/* 12.18 shared_ptr为什么没有release成员？*/
// shared_ptr指向同一块内存的指针并不唯一，
// 如果shared_ptr用release成员，则当任一
// 指向某一内存块的指针被释放后，
// 其他指向改内存块的指针仍然可以释放该内存块
// 因此shared_ptr的release成员是无意义的

// shared_ptr cannot give away ownership unless it's unique()
// because the other copy will still destory the object.
// Consider:
// shared_ptr<int> a(new int);
// shared_ptr<int> b(a);		// a.use_count() == b.use_count() == 2
//
// int *p = a.release();
//
// Who owns p now? b will still can delete on it in its destructor.
// Furthermore, the pointer returned by release() would be difficult
// to deallocate reliably, as the source shared_ptr could have been
// created with a custom deleter.
// Ref. https://stackoverflow.com/questions/1525764/how-to-release-pointer-from-boostshared-ptr

#include<iostream>
#include<memory>

using namespace std;
using IntP = unique_ptr<int>;

int main()
{
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	// a
	//IntP p0(ix);
	// 非法，无法将int转换为std::nullptr_t

	// b
	//IntP p1(pi);
	// 非法，但是编译通过
	// 当p1离开作用域时会自动释放，但是pi不是动态申请的，程序出错

	// c
	//IntP p2(pi2);
	// 非法，但是编译通过
	// p2离开作用域时会释放p2指向的内存（也即pi2指向的内存）
	// 使pi2变成了空悬指针(dangling pointer)

	//d 
	//IntP p3(&ix);
	// 非法
	// 当p3离开作用域时会释放p3指向的内存（即&ix指向的内存）
	// 但是ix不是动态申请的，程序出错

	// e
	//IntP p4(new int(2048));
	// 合法 p4指向一个值为2048的int

	// f
	//IntP p2(new int(233));
	//IntP p5(p2.get());
	// 非法
	// p2 p5同时指向同一块内存，当p2 p5离开作用域时
	// 都会释放其指向的内存，造成二次释放，程序出错

	return 0;
}

