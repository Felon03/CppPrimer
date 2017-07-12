#include"15.21_GraphicsPrimitives.h"
#include<iostream>

using std::cout;
using std::endl;

int main()
{
	Box box;
	cout << box.shape_name() << endl;
	box.resize_by_percentage(4.0f);
	cout << "The volume of " << box.shape_name() << ": " << box.volume() << endl;

	Circle circle;
	cout << circle.shape_name() << endl;
	circle.resize_by_percentage(2.f);
	cout << "The area of " << circle.shape_name() << " " << circle.area() << endl;

	Sphere sphere;
	cout << sphere.shape_name() << endl;
	sphere.resize_by_percentage(2.f);
	cout << "The volume of " << sphere.shape_name() << ": " << sphere.volume() << endl;

	Cone cone;
	cout << cone.shape_name() << endl;
	cone.resize_by_percentage(2.f);
	cout << "The volume of " << cone.shape_name() << ": " << cone.volume() << endl;
	return 0;
}