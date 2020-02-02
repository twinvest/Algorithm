#include<iostream>
#include<queue>
#pragma warning (disable : 4996)
using namespace std;
int parksize, numOfcar;
bool isEmpty_parkingArea(int park[])
{
	bool flag;
	for (int i = 1; i <= parksize; ++i)
		if (park[i] == 0) 
			return flag = true;
	return flag = false;
}

int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		queue<int> q;
		int sum = 0;
		int parkingArea[101] = {0,}; //������
		int parkingAreaprice[101]; //i��° ���������� ���� ���Դ� ����
		int carWeight[2001]; //������ ����
		int order[4001];

		cin >> parksize;
		cin >> numOfcar;

		//�������� �����ŭ i��° ���������� ���� ���Դ� ������ �Է¹���
		for (int i = 1; i <= parksize; ++i)
		{
			scanf("%d", &parkingAreaprice[i]);
		}

		for (int i = 1; i <= numOfcar; ++i)
		{
			scanf("%d", &carWeight[i]);
		}

		for (int i = 1; i <= 2 * numOfcar; ++i)
		{
			int carnum;
			scanf("%d", &carnum);
			order[i] = carnum;
		}

		for (int i = 1; i <= 2 * numOfcar; ++i)
		{
			int curCar = order[i];
			//i��° ������ 0���� ũ�鼭 �������� ���������
			if (curCar > 0 && isEmpty_parkingArea(parkingArea))
			{
				//��� �ִ� ���� �� ���� ���� �ε����� ã�Ƽ� ���� ���.
				for (int j = 1; j <= parksize; ++j)
				{
					if (parkingArea[j] == 0)
					{
						parkingArea[j] = curCar;
						//�׸��� ���� ���ڸ��� ����� ¡���Ѵ�.
						sum += parkingAreaprice[j] * carWeight[curCar];
						break;
					}
				}
			}
			//i��° ������ 0���� ������
			else if (curCar < 0)
			{
				//���� �Ǿ��ִ� ���� ����.
				//�׷��� ���� ���⼭ ���� ���µ� ť�� ����ϴ� ���� �ִٸ� �� ���� ���� ���ڸ��� �ٷ� ����ִ´�.
				for (int j = 1; j <= parksize; ++j)
				{
					if (parkingArea[j] == abs(curCar))
					{
						parkingArea[j] = 0;
						if (!q.empty())
						{
							parkingArea[j] = q.front();
							q.pop();
							sum += parkingAreaprice[j] * carWeight[parkingArea[j]];
							break;
						}
					}
						
				}
			}
			//�������� �������ִµ� i��° ������ 0����ũ��
			else if (curCar > 0 && !isEmpty_parkingArea(parkingArea))
			{
				//ť���� ����Ѵ�.
				q.push(curCar);
			}
		}
		printf("#%d %d\n", t, sum);
	}
}