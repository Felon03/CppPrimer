/*修改统计元音字母程序，使其能统计空格、制表符和换行符*/
#include<iostream>

using namespace std;

int main()
{
	char ch;
	unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
		spaceCnt = 0, tabCnt = 0, newLineCnt = 0;
	while (cin >> std::noskipws >> ch)		// std::noskipws 不忽略空格 
	{
		switch (ch)
		{
		case 'a':
		case 'A':
			++aCnt;
			break;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i':
		case 'I':
			++iCnt;
			break;
		case 'o':
		case 'O':
			++oCnt;
			break;
		case 'u':
		case 'U':
			++uCnt;
			break;
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++newLineCnt;
			break;
		default:
			break;
		}
	}

	cout << "Numer of vowel a(A): " << aCnt << endl
		<< "Number of vowel e(E): " << eCnt << endl
		<< "Number of vowel i(I): " << iCnt << endl
		<< "Number of vowel  o(O): " << oCnt << endl
		<< "Number of vowel u(U): " << uCnt << endl
		<< "Number of space: " << spaceCnt << endl
		<< "Number of new line: " << newLineCnt << endl
		<< "Number of tab char: " << tabCnt << endl;

	return 0;
}