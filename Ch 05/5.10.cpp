/*编写程序，使其能同时统计大小写的元音字母*/
#include<iostream>

using namespace std;

int main()
{
	char ch;
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, sCnt = 0, nCnt = 0, tCnt = 0;
	int otherCnt = 0;
	while ((ch = getchar()) != EOF)		// 统计字符用getchar
	{
		if (ch == 'a' || ch == 'A')
			++aCnt;
		else if (ch == 'e' || ch == 'E')
			++eCnt;
		else if (ch == 'i' || ch == 'I')
			++iCnt;
		else if (ch == 'o' || ch == 'O')
			++oCnt;
		else if (ch == 'u' || ch == 'U')
			++uCnt;
		else if (ch == ' ')
			++sCnt;
		else if (ch == '\n')
			++nCnt;
		else if (ch == '\t')
			++tCnt;
		else
			++otherCnt;
	}

	cout << "Number of vowel a: " << aCnt << endl
		<< "Number of vowel e: " << eCnt << endl
		<< "Number of vowel i: " << iCnt << endl
		<< "Number of vowel o: " << oCnt << endl
		<< "Number of vowel u: " << uCnt << endl
		<< "Number of space: " << sCnt << endl
		<< "Number of \\n: " << nCnt << endl
		<< "Number of \\t: " << tCnt << endl
		<< "Numer of other allphabets: " << otherCnt << endl;

	return 0;
}