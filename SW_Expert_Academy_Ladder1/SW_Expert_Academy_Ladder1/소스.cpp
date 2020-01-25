#include<iostream>
using namespace std;
int arr[100][100];
int dir[3][2] = { {0, -1}, {0, 1}, {-1, 0} };

bool inside(int y, int x)
{
	return (y >= 0 && y < 100) && (x >= 0 && x < 100);
}

int main()
{
	int testcase, ans, curx, cury, nextx, nexty;
	for (int t = 1; t <= 10; t++)
	{
		cin >> testcase;
		if (testcase == t)
		{
			//�Է¹ޱ�
			for (int i = 0; i < 100; ++i)
				for (int j = 0; j < 100; ++j)
					scanf("%d", &arr[i][j]);

			//2�ΰ� ã��
			for (int i = 0; i < 100; ++i)
			{
				if (arr[99][i] == 2)
				{
					curx = i;
					cury = 99;
				}
			}

			//��ĭ�� ���ΰ��µ�
			for (int i = 99; i >= 0; --i)
			{
				//�ö󰥶� ���� 3������ �Ⱦ��ش�. ����, ������, ��(�̶� ���� ���� �ʰ� �ȴ´�.)
				for (int j = 0; j < 3; ++j)
				{
					int nextx = curx + dir[j][1];
					int nexty = cury + dir[j][0];

					//������ nexty�� -1�� �������� �� ���ܻ�Ȳ ó��
					if (nexty == -1)
						nexty = 0;

					//���� ����� �߱�
					if (!inside(nexty, nextx))
						continue;

					//������ ����� �ʾ����� 3���� �� �ϳ��� ������.
					//�����̳� �������� ��
					if (j == 0 || j == 1)
					{
						if (arr[nexty][nextx] == 1)
						{
							arr[cury][curx] = 3;
							curx = curx + dir[j][1];
							cury = cury + dir[j][0];
							++i;
							break;
						}
					}
					//���ΰ���
					else
					{
						if (arr[nexty][nextx] == 1)
						{
							arr[cury][curx] = 3;
							curx = curx + dir[j][1];
							cury = cury + dir[j][0];
						}
					}
				}
			}

			//0���� �Ⱦ 3�� ������ �װ� ����
			for (int i = 0; i < 100; ++i)
				if (arr[0][i] == 3)
					ans = i;
			printf("#%d %d\n", t, ans);
		}
	}
}