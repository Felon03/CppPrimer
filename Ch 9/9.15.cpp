/*��д�����ж�����vector<int>�Ƿ����*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vec1{ 1,2,3,4,5,6 };
	vector<int> vec2{ 1,2,3,4,5,6 };
	vector<int> vec3{ 1,2,3,4,5 };

	cout <<boolalpha<< (vec1 == vec2) << endl
		<< (vec2 == vec3) << endl;
}