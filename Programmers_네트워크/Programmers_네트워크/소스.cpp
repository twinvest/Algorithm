#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
vector<vector<bool>> visit;

void dfs(int start, vector<vector<int>>& computers, int n) 
{
	//start�� solution���� ù ��� ȣ���� ���� ��ǻ�� �ѹ�����. �ι�° ���ȣ����ʹ� j�� ����Ǹ鼭 ����� ��ǻ�͸� ��� ã�� ���ִ� ����.
	//����, ���� ����Ǿ� �ִٸ� solution���� ù��° ���ȣ�� �� start�� ��� j�� ���ϸ鼭 ����� ��� ��ǻ�͸� ã�����̴�.
	for (int j = 0; j < n; j++)
	{
		if (computers[start][j] == 1 && !visit[start][j])
		{
			visit[start][j] = true;
			dfs(j, computers, n);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	//2�������Ϳ� size�ο�
	visit.assign(n, vector<bool>(n, 1));
	//2���� ���� �ʱ�ȭ
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visit[i][j] = false;


	int answer = 0;
	//Ž������
	for (int i = 0; i < n; i++)
	{
		//i�� �ϳ��� ��ǻ�͸� �ǹ��Ѵٰ� �����ض�. ���� ���, ù��° �׽�Ʈ���̽��� [2][2]�� ����° ��ǻ�͸� Ž���� �� �� �ڵ�� �ſ� ������.
		if (!visit[i][i])
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
	int N = 7;
	
	vector<int> t1;
	t1.push_back(1);
	t1.push_back(1);
	t1.push_back(1);
	t1.push_back(0);
	t1.push_back(0);
	t1.push_back(0);
	t1.push_back(0);

	vector<int> t2;
	t2.push_back(1);
	t2.push_back(1);
	t2.push_back(1);
	t2.push_back(0);
	t2.push_back(0);
	t2.push_back(0);
	t2.push_back(0);
	
	
	vector<int> t3;
	t3.push_back(1);
	t3.push_back(1);
	t3.push_back(1);
	t3.push_back(0);
	t3.push_back(0);
	t3.push_back(0);
	t3.push_back(0);

	vector<int> t4;
	t4.push_back(0);
	t4.push_back(0);
	t4.push_back(0);
	t4.push_back(1);
	t4.push_back(0);
	t4.push_back(0);
	t4.push_back(1);

	vector<int> t5;
	t5.push_back(0);
	t5.push_back(0);
	t5.push_back(0);
	t5.push_back(0);
	t5.push_back(1);
	t5.push_back(1);
	t5.push_back(0);

	vector<int> t6;
	t6.push_back(0);
	t6.push_back(0);
	t6.push_back(0);
	t6.push_back(0);
	t6.push_back(1);
	t6.push_back(1);
	t6.push_back(0);
	
	vector<int> t7;
	t7.push_back(0);
	t7.push_back(0);
	t7.push_back(0);
	t7.push_back(1);
	t7.push_back(0);
	t7.push_back(0);
	t7.push_back(1);

	arr.push_back(t1);
	arr.push_back(t2);
	arr.push_back(t3);
	arr.push_back(t4);
	arr.push_back(t5);
	arr.push_back(t6);
	arr.push_back(t7);


	start = clock();
	int ans = solution(N, arr);
	end = clock();
	printf("%d\n", ans);
	printf("%f", end - start);

}