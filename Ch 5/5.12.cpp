/*修改统计元音字母程序，使其能统计以下含有两个字符的字符序列的数量： ff、fl和fi*/
#include<iostream>

using namespace std;

int main()
{
	char ch, prech = '\0';	// 用prech记录前一个字符，初始为空
	unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
		spaceCnt = 0, tabCnt = 0, newLineCnt = 0,
		ffCnt = 0, flCnt = 0, fiCnt = 0;
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
			if (prech == 'f') ++fiCnt;
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
		case 'f':
			if (prech == 'f') ++ffCnt;
			break;
		case 'l':
			if (prech == 'f') ++flCnt;
			break;
		default:
			break;
		}
		prech = ch;
	}

	cout << "Numer of vowel a(A): " << aCnt << endl
		<< "Number of vowel e(E): " << eCnt << endl
		<< "Number of vowel i(I): " << iCnt << endl
		<< "Number of vowel  o(O): " << oCnt<<endl
		<< "Number of vowel u(U): " << uCnt<< endl
		<< "Number of space: " << spaceCnt << endl
		<< "Number of new line: " << newLineCnt << endl
		<< "Number of tab char: " << tabCnt << endl
		<< "Number of ff: " << ffCnt << endl
		<< "Number of fl: " << flCnt << endl
		<< "Number of fi: " << fiCnt << endl;

	return 0;
}