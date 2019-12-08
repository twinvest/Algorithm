#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
#pragma warning(disable : 4996)
#define MAX 25

using namespace std;
int arr[MAX][MAX];
int visit[MAX][MAX] = {false, };
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,1 },{ 0,-1 } }; //�� �� ������ ����
int N; //�迭�� ������ �ǹ��ϴ� N
int danji = 0;
vector<int> ans_vector; //����� ����� ������� ������ �����Ұ���.

//���ι��� ����
bool inside(int m, int n) 
{
	return (n >= 0 && n < N) && (m >= 0 && m < N);
}

//Ž���ڵ� dfs
int dfs(int arr[MAX][MAX], int y, int x)
{
	int count = 0;
	//1�̸� �湮�ؾ���
	if (arr[y][x] == 1)
	{
		count++;                //count�ø���
		visit[y][x] = true;     //�湮�迭 true�� �������
	}
		
	//4����Ž��
	for (int i = 0; i < 4; i++)
	{
		//���� �˻��Ұ�
		int nx = x + dir[i][0], ny = y + dir[i][1];
		//���� ����� continue
		if (!inside(nx, ny)) continue;
		//1�ε� ���� �湮���� ���� ���� ==>Ž���ؾ���!!
		else if (arr[ny][nx] == 1 && visit[ny][nx] == false)
		{
			int ret = dfs(arr, ny, nx);
			count += ret;  //��ȯ���� count�� ���������~~dfs�ϱ�!
		}
	}
	return count;
}

int main() {
	
	scanf("%d", &N);
	//�Էº�
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			scanf("%d", &arr[i][j]);

	//Ž������
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (arr[i][j] == 1 && visit[i][j] == false)
			{
				++danji;
				int ans = dfs(arr, i, j);
				ans_vector.push_back(ans);
			}

		}
	}
	
	printf("%d\n", danji);
	//���� ��������
	sort(ans_vector.begin(), ans_vector.end());
	for (int i = 0; i < ans_vector.size(); ++i)
	{
		printf("%d\n", ans_vector[i]);
	}

}