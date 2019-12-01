#include <string>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int, vector<int>, less<int>> pq;
	int index = 0;

	for (int i = 0; i < k; i++) 
	{
		//�ϴ� ���� ���� �Ǹ� ���� pq�� ������
		if (dates[index] == i) 
		{
			pq.push(supplies[index]);
			index++;
		}
		//stock�� 0�� �ȳ��� pq���� ���� ���� ���� ���� �߰��ϰ� answer�� ++��
		if (stock == 0) 
		{
			stock = pq.top();
			pq.pop();
			answer++;
		}
		//stock�� ���� 1�� ����
		stock--;
	}
	return answer;
}


int main()
{
	int stock = 4;
	vector<int> dates;
	dates.push_back(4);
	dates.push_back(10);
	dates.push_back(15);

	vector<int> supply;
	supply.push_back(20);
	supply.push_back(5);
	supply.push_back(10);
	int K = 30;
	int ans = solution(stock, dates, supply, K);
	printf("%d", ans);
}