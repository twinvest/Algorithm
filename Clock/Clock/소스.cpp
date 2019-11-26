#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 9999
#define SWITCH 10
#define CLOCK 16
//linked[i][j]=1 i�� ����ġ�� j�� �ð谡 ����Ǿ� �ִ�
//linked[i][j]=0 i�� ����ġ�� j�� �ð谡 ����Ǿ� ���� �ʴ�
int linked[SWITCH][CLOCK] = {
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

//��� �ð谡 12�ø� ����Ű�� �ִ��� Ȯ��
bool areAligned(const vector<int>& clocks)
{
	for (int i = 0; i < CLOCK; i++)
		if (clocks[i] != 12)
			return false;
	return true;
}

//switch�� ����ġ�� ������. ��, ���ڷ� ���� ����ġ�� ��ȣ�� ����� ��� �ð踦 �ѹ��� ������ �ڵ���.
void push(vector<int>& clocks, int swtch)
{
	for (int clock = 0; clock < CLOCK; clock++)
		if (linked[swtch][clock] == 1)
		{
			clocks[clock] += 3;
			if (clocks[clock] == 15) //3, 6, 9, 12���� �̹Ƿ�
				clocks[clock] = 3;
		}
}

//clocks:���� �ð���� ����
//swtch:�̹��� ���� ����ġ�� ��ȣ
//�� �־��� ��, ���� ����ġ���� ������ clocks�� 12�÷� ���� �� �ִ� �ּ� Ƚ���� ��ȯ
//���� �Ұ����ϴٸ� INF �̻��� ū ���� ��ȯ
int solve(vector<int>& clocks, int swtch)
{
	if (swtch == SWITCH)
		return areAligned(clocks) ? 0 : INF;
	//�� ����ġ�� 0�� ������ ������ ���� ������ �������� ��� �õ�(12�ø� 0��, 3�ø� 3��)
	int result = INF;
	for (int cnt = 0; cnt < 4; cnt++)
	{
		result = min(result, cnt + solve(clocks, swtch + 1));

		push(clocks, swtch);
	}
	//push(clocks, swtch)�� �׹� ȣ��Ǿ����� clocks�� ������ ���� ����
	return result;
}
int main(void)
{
	int test_case;
	vector<int> clocks(CLOCK);
	cin >> test_case;
	if (test_case < 0 || test_case>30)
		exit(-1);
	for (int i = 0; i < test_case; i++)
	{
		for (int j = 0; j < CLOCK; j++)
			cin >> clocks[j];
		int result = solve(clocks, 0);
		if (result == INF)
			cout << -1 << endl;
		else
			cout << result << endl;
	}
	return 0;
}