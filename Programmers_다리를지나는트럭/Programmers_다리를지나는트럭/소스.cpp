#include <string>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int weight_now = 0;
	queue<int> times, entered_weights;
	for (int i = 1;; i++)
	{
		if (times.size() > 0)
		{
			// �ٸ��� �� �տ� �ִ� Ʈ���� �ٸ��� �� �ǳ��� ��
			if (i - times.front() == bridge_length)
			{
				// Ʈ���� �ٸ��� �� �ǳ� �� ���� ������ �ð���(����� �ð� + �ٸ� ����) �������ش�.
				int finish_time = bridge_length + times.front();
				// �� �ǳ� Ʈ���� ������ �������ְ� �ٸ��� �ߵ�� ���Ե� �����Ѵ�.
				times.pop();
				weight_now -= entered_weights.front();
				entered_weights.pop();
				//�ǳʾ��� Ʈ���� �� �̻� ���� �ǳʴ� ���� Ʈ���� ���� ��
				if (truck_weights.size() == 0 && entered_weights.size() == 0)
				{
					//������ Ʈ���� �� �ð��� �����Ѵ�.
					return finish_time;
				}
			}
		}
		//�ٸ��� �Ѱ� ����ġ�� �ʰ��ϱ� ������ Ʈ���� �ٸ� ���� �ø���.
		while (1)
		{
			// �ٸ��� Ʈ���� �� ���� ���ϰų� �� �̻� �� Ʈ���� ������ break
			if (truck_weights.size() == 0 || weight_now + truck_weights.front() > weight)
			{
				break;
			}
			else {
				// �ٸ��� ���� Ʈ���� ���԰� �߰��ȴ�.
				weight_now += truck_weights.front();
				// �ٸ��� ���� Ʈ���� ���Կ� ���� �ð��� ����Ѵ�.
				entered_weights.push(truck_weights.front());
				times.push(i);
				truck_weights.erase(truck_weights.begin());
				break;
			}
		}

	}
}
int main()
{
	vector<int> v;
	
	int bridge_length = 2;
	int weight = 10;
	
	v.push_back(7);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	int ans = solution(bridge_length, weight, v);
	printf("%d", ans);
}