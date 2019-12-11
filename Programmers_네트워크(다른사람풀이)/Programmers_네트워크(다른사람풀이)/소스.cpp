#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
bool visit[200];

//��ó���� �ܼ��� 1���� �迭�� ����ߴٰ� �����ߴµ� �̰� 2�����迭 ����������ϰ� 1�����迭 ����������ϰ� ������ Ƚ���� �ſ� �޶���.
//1���� �迭������ �밢���� �ִ°� Ȯ���Ҷ� ������ �ȵ�. �������, 0 1 Ȯ���ϰ� 1 0 Ȯ���� ��!
//�ٵ� 2���� �迭������ ���Ե�. �� ������ 0 1 Ȯ���ϰ� 1 0 ���� ���� �� �ٽ� 0 0 ���� ���ٴ� ����.
//���� 1�����̳� 2�����̳� �� ������ ����ϱ� ��. �׷���, 1���� �迭�� ���� �޸������γ� �ð������γ� �����.
//�׽�Ʈ���̽� 11������ 0.19ms, 0.5ms�� �ð��� ��µǴµ� 0.14ms��ŭ�� ���̰� ��.
//�ΰ��� �Ӹ��� ���������� �ڵ带 �����ϱ⿡�� 2���� �迭�� �� ���ѵ�.
void dfs(int start, vector<vector<int>>& computers, int n) {
	visit[start] = 1;
	for (int j = 0; j < n; j++)
	{
		if (!visit[j] && computers[start][j] && (start != j) ) //start != j ������ ���� ������ ���� �߰���.
			dfs(j, computers, n);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	//n���� ��ǻ�Ͱ� �����ϱ� for���� n���� ����.
	for (int i = 0; i < n; i++)
	{
		//�տ� �ڵ�� �ٸ� ���� 2���� �迭��� visit�迭�� 1�������� ����� ���̴�. ����, �� visit�迭�� i�� ��ǻ���� ��ȣ�� �ǹ��ϱ⵵ �Ѵ�.
		if (!visit[i]) //����, i��° ��ǻ�͸� �湮���� �ʾҴٸ�
		{
			answer++;
			dfs(i, computers, n);
		}
	}
	return answer;
}

int main()
{
	clock_t start, end;
	vector<vector<int>> arr;
	int N = 3;
	vector<int> t1;
	t1.push_back(1);
	t1.push_back(1);
	t1.push_back(0);

	vector<int> t2;
	t2.push_back(1);
	t2.push_back(1);
	t2.push_back(1);

	vector<int> t3;
	t3.push_back(0);
	t3.push_back(1);
	t3.push_back(1);

	arr.push_back(t1);
	arr.push_back(t2);
	arr.push_back(t3);
	start = clock();
	int ans = solution(N, arr);
	end = clock();
	printf("%d\n", ans);
	printf("%f", end - start);

}