#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define N 11
#define INF 987654321
using namespace std;

int map[N][N], ans = INF;
bool visited[N][N];

int paperCnt[6];//�� �����̸� ����� Ƚ���� ���� 

typedef pair<int, int> pp;
vector<pp> fillSpace;

bool check(int x, int mx, int y, int my) {
	//mx, my�� max_x, max_y�� �������� ��� 
	if (mx > N - 1 || my > N - 1) return false;

	for (int i = x; i < mx; i++) {
		for (int j = y; j < my; j++) {
			if (visited[i][j]) return false;
			if (!map[i][j]) return false;
		}
	}
	return true;
}
//cnt�� ����� �������� ����, fill�� ä��ĭ�� ��
void dfs(int cnt, int fill) {
	if (fill == fillSpace.size()) 
	{
		ans = min(ans, cnt);
		return;
	}
	if (ans <= cnt) return; //�̹� �ִ밪�� �Ѿ����

	//5*5���� ���ʴ�� �� �� �մ� ���� ä������.
	for (int i = 0; i < fillSpace.size(); i++) 
	{
		int x = fillSpace[i].first;
		int y = fillSpace[i].second;

		if (visited[x][y]) continue; //�̹� ä���� ĭ 

		for (int j = 5; j > 0; j--) 
		{
			if (paperCnt[j] > 4) {
				//�ִ� 5������� ��� ���� 
				continue; //�ٸ� ������ ���
			}

			int nx = x + j;
			int ny = y + j; //5*5 , 4*4 ... �̱� ������ j��ŭ �÷��ش�.

			if (check(x, nx, y, ny)) 
			{
				//j������ �����̷� ä���� �� �ִ� �����̶��
				for (int k = x; k < nx; k++) 
				{
					for (int z = y; z < ny; z++) 
					{
						visited[k][z] = true; //�湮 ǥ��->ä���ٴ� �ǹ�
					}
				}
				paperCnt[j]++; //������ �ϳ� �� 

				dfs(cnt + 1, fill + j * j); //j*j��ŭ ä���� 

				///////////��Ʈ��ŷ////////////////////
				for (int k = x; k < nx; k++) 
				{
					for (int z = y; z < ny; z++) 
					{
						visited[k][z] = false; //�湮 ǥ��->ä���ٴ� �ǹ�
					}
				}
				paperCnt[j]--;
				///////////��Ʈ��ŷ////////////////////
			}
		}
		return;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			cin >> map[i][j];
			if (map[i][j]) fillSpace.push_back(pp(i, j));
		}
	}
	//input 
	dfs(0, 0); //�����̸� ����� Ƚ��, ä�� ĭ�� �� 

	if (ans == INF) ans = -1;
	cout << ans << '\n';
	return 0;
}