#include <iostream>
#include <cstring>
#pragma warning(disable: 4996)
using namespace std;
struct offsets
{
	int x, y;
};
offsets moveDir[8] = { { -1, 0 },{ -1, 1 },{ 0, 1 },{ 1, 1 },{ 1, 0 },{ 1, -1 },{ 0, -1 },{ -1, -1 } };
char word[11]; //���������� ����
char board[5][5]; //5*5 Boggle
bool record[5][5][10]; //��Ͽ�(���ÿ� �����ִ� �ܾ��� ���̰� 10�� �ʰ����� �ʱ� ������ ���̸� ���Ƿ� 10�̶�� ����)
bool search(int y, int x, int idx)
{
	record[y][x][idx] = 1; //�湮�ߴٴ� ���� ���
	//ù ���ڿ� �������� ������ �ش� ������ �ƴϴ�
	if (board[y][x] != word[idx])
		return false;
	//������ ���ڱ��� �����ϴٸ� ��
	if (idx == strlen(word) - 1)
		return true;
	for (int i = 0; i < 8; i++)
	{
		if (y + moveDir[i].y < 5 && x + moveDir[i].x < 5 && y + moveDir[i].y >= 0 && x + moveDir[i].x >= 0)
		{
			if (record[y + moveDir[i].y][x + moveDir[i].x][idx + 1])
				continue;//�̹� �湮�ߴٸ� �� �ٽ� �湮�� �ʿ� ����
			if (search(y + moveDir[i].y, x + moveDir[i].x, idx + 1))
				return true;//��� ȣ��
		}
	}
	return false;
}
void answer(void)
{
	int  word_num;
	for (int i = 0; i < 5; i++)
		scanf("%s", board[i]);
	scanf("%d", &word_num);
	for (int j = 0; j < word_num; j++)
	{
		memset(record, 0, sizeof(record));
		scanf("%s", word);
		printf("%s ", word);
		bool result = false;
		for (int k = 0; k < 5; k++)
		{
			for (int l = 0; l < 5; l++)
			{
				if (search(k, l, 0)) result = true;
				if (result) break; //ã�Ҵٸ� �ݺ��� Ż��
			}
			if (result) break;
		}

		if (result)	puts("YES");
		else puts("NO");
	}
}

int main(void)
{
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
		answer();
	return 0;
}