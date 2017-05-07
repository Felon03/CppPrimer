/*�ڵ�316ҳ�еĳ����У��������
 iter = vi.insert(iter, *iter++);
 �Ƿ�Ϸ�
 */
/*���Ϸ�
//  @Answer the statement is illegal, cause as said in Standard [5.2.2] :
//          "The order of evaluation of arguments is unspecified."
//          As a result, after entering function insert,
//          iter could be its original value or original value + 1 or even
//          anything else,
//          depending on how compiler implemented.
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();		// ���� begin������cbegin����ΪҪ�ı�vi
	while (iter != vi.end())
	{
		if (*iter % 2)
		{
			iter = vi.insert(iter, *iter);
			//advance(iter, 2);
			iter += 2;
		}
		else
			iter = vi.erase(iter);		// iterָ��ɾ��Ԫ��֮���Ԫ��
	}

	for (auto x : vi) cout << x << " ";
	cout << endl;

	return 0;
}