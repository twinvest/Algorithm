#include <iostream>
using namespace std;
//�־��� ĭ�� ���� �� �ִ� �װ��� ���
//����� �����ϴ� �� ĭ�� ����� ��ġ (dy, dx)�� ���
const int coverType[4][3][2] = {
	//����
	//��
	{{0,0}, {1, 0}, {0, 1}},
	//����
	//  ��
	{{0, 0}, {0, 1}, {1, 1}},
	//��
	//����
	{{0, 0}, {1, 0}, {1, 1}},
	//  ��
	//����
	{{0, 0}, {1, 0}, {1, -1}}
};

//board�� (y, x)�� type�� ������� ���ų�, ������ ����� ���ش�
//push�� 1�̸� ����, -1�̸� ������ ����� ���ش�
//���� ����� ����� ������ ���� ���(������ ������ �����ų�
//��ġ�ų� ���� ĭ�� ���� ��) false ��ȯ
bool set(int board[][20], int y, int x, int H, int W, int type, int push)
{
	bool ok = true;
	for (int i = 0; i < 3; i++)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= H || nx < 0 || nx >= W) //������ �ʰ��� ���
			ok = false;
		else if ((board[ny][nx] += push) > 1) //������ ���
			ok = false;
	}
	return ok;
}

//board�� ��� �� ĭ�� ���� �� �ִ� ����� ���� ��ȯ
//board[i][j]=1 �̹� ���� ĭ Ȥ�� ���� ĭ
//board[i][j]=0 ���� ������ ���� ĭ
int cover(int board[][20], int H, int W)
{
	//���� ä���� ���� ĭ �� ���� ���� ���ʿ� �ִ� ĭ�� ã�´�
	int y = -1, x = -1;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			if (!board[i][j]) //���� ä���� ���� ĭ ã��
			{
				y = i;
				x = j;
				break;
			}
		if (y != -1)
			break;
	}
	//���� ���: ��� ĭ�� ä������ 1�� ��ȯ
	if (y == -1)
		return 1;
	int result = 0;
	for (int type = 0; type < 4; type++)
	{
		//���� board[y][x]�� type ���·� ���� �� ������ ��� ȣ��
		if (set(board, y, x, H, W, type, 1))
			result += cover(board, H, W);
		//������ ��� ġ���
		set(board, y, x, H, W, type, -1);
	}
	return result;
}

int main(void)
{
	int test_case, H, W; //H=height, W=width
	int board[20][20];
	char bw[20]; //black/white

	cin >> test_case;
	if (test_case < 0 || test_case > 30)
		exit(-1);
	for (int i = 0; i < test_case; i++)
	{
		cin >> H >> W;
		if (H < 1 || H>20 || W < 1 || W>20)
			exit(-1);
		for (int i = 0; i < H; i++)
		{
			cin >> bw;
			for (int j = 0; j < W; j++)
				board[i][j] = (bw[j] == '#') ? 1 : 0;
		}
		cout << cover(board, H, W) << endl;
	}
	return 0;
}