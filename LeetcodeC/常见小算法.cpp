#include <map>
#include <iostream>
#include <string>
using namespace std;

//求共同好友数量
/*
描述
Alice有N个朋友，Bob有M个朋友。 他们想知道有多少人是他们的共同朋友。 你能帮助他们吗？
输入:
输入以整数T（T <= 20）开始，表示测试样例的数量。 每个测试样例包含三行。 第一行包含两个整数N和M（1 <= N，M <= 50）。 第二行包含N个名字，代表Alice的朋友。 第三行包含M个名字，代表Bob的朋友。 每个名字的长度在3到10之间。 每个名称只包含小写英文字母（'a' - 'z'）。 保证两个不同的人不会共享相同的名称。
输出:
对于每个样例，用一行输出Alice和Bob的共同朋友的数目。
输入样例:
2
4 5
tom lucy kate eva
eva rose joe carl tom
3 3
jimmy jeff emily
zhanglan xiemin xiaran
输出样例
2
0
*/
void findCommonFriendsOfAlice()
{
	map<string, int> friends;
	string str;
	int n, a, b, i, count;
	scanf("%d", &n);

	while (n--)
	{
		count = 0;
		scanf("%d %d", &a, &b);
		for (i = 0; i < a; i++)
		{
			cin >> str;
			friends[str] += 1;
		}

		for (i = 0; i < b; i++)
		{
			cin >> str;
			if (friends[str] > 0)
			{
				count++;
			}
		}
		printf("%d\n", count);
	}
}
