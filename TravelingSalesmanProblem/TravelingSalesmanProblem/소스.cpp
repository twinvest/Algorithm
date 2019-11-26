#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int dist[15][15];

//len�� ���ݱ��� ���� ����� ����
int TSP(vector<int> path, vector<bool> visited, int len) 
{
	//��� ���ø� �� �湮���� ���
	if (path.size() == n) return len + dist[path.back()][0];
	int ret = 987654321;

	for (int next = 0; next < n; next++) {
		//�湮 �ߴٸ� �ٽ� ÷����
		if (visited[next] == true) continue;

		int cur = path.back();
		path.push_back(next);
		visited[next] = true;
		ret = min(ret, TSP(path, visited, len + dist[cur][next]));
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cin >> dist[i][j];
		}
	}

	vector<int> path(1, 0); //��θ� ������ ����.
	vector<bool> visited(n, false); //�湮 ���θ� ������ ����. false�� �ʱ�ȭ
	visited[0] = true; //��� ���� �湮���� üũ
	double ret = TSP(path, visited, 0);
	cout << ret << endl;
}