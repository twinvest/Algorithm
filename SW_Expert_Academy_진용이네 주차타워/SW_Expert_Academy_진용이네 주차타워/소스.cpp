#include<iostream>
#include<queue>
#pragma warning (disable : 4996)
using namespace std;
int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		queue<int> q;
		int sum = 0;
		int parking[101] = {0,};
		int price[101];
		int car[2001];

		int parksize, numOfcar;
		cin >> parksize;
		cin >> numOfcar;

		for (int i = 1; i <= parksize; ++i)
		{
			scanf("%d", &price[i]);
		}

		for (int i = 1; i <= numOfcar; ++i)
		{
			scanf("%d", &car[i]);
		}

		bool flag = true;
		for (int i = 1; i <= 2 * numOfcar; ++i)
		{
			int carnum;
			scanf("%d", &carnum);
			for (int j = 1; j <= parksize; ++j)
			{
				//����
				if (carnum > 0)
				{
					if (parking[j] == 0 && flag)
					{
						parking[j] = carnum;
						if (j == parksize) 
							flag = false;
						break;
					}
					if(!flag)
					{
						q.push(carnum);
					}
						
				}
				//����
				else
				{
					if (parking[j] == abs(carnum))
					{
						sum = sum + (car[abs(carnum)] * price[j]);
						parking[j] = 0;
						//q�� ���� �ʾҴٸ� ������ ���� �������ϱ� j�� �ڸ��� ť�� �Ǿճ��� �־�
						if (!q.empty())
						{
							parking[j] = q.front();
							q.pop();
						}
						break;
					}
				}
			}
		}
		printf("#%d", sum);
	}
}