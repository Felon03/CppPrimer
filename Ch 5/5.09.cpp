/*编写一段程序，使用一系列if语句统计从cin读入的文本中有多少元音字母*/
#include<iostream>

using namespace std;

int main()
{
	char ch;
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	int otherCnt = 0;
	while (cin >> ch)
	{
		if (ch == 'a')
			++aCnt;
		else if (ch == 'e')
			++eCnt;
		else if (ch == 'i')
			++iCnt;
		else if (ch == 'o')
			++oCnt;
		else if (ch == 'u')
			++uCnt;
		else
			++otherCnt;
	}

	cout << "Number of vowel a: " << aCnt << endl
		<< "Number of vowel e: " << eCnt << endl
		<< "Number of vowel i: " << iCnt << endl
		<< "Number of vowel o: " << oCnt << endl
		<< "Number of vowel u: " << uCnt << endl
		<< "Numer of other allphabets: " << otherCnt << endl;

	return 0;
}