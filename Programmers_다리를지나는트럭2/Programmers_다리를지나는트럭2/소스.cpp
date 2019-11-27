#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<int> q;
	int sum, count; sum = count = 0;
	for (int i = 0; i < truck_weights.size(); i++) {
		int d = truck_weights[i];
		while (true) 
		{
			if (q.empty()) 
			{
				q.push(d);
				count++;
				sum += d;
				break;
			}
			//�ٸ��� ���̸� �̷��� ǥ��. �ö� �� �ִ� ���� ���� ���
			else if (q.size() == bridge_length)  
			{
				sum -= q.front(); 
				q.pop();
			}
			//�ٸ� ���� �ö� �� �ִ� ���� ������ �ִ� ���
			else 
			{
				//���Ը� �������µ�, ���� �ʰ��� ���. ���̵�����(0)�� �ϳ� �־��ش�(�̴� ���� ��ĭ �̵��ϴ� ȿ����)
				if (sum + d > weight) 
				{
					q.push(0);
					count++;
				}
				//���԰� �ʰ����� ���� ���. ���� �ø���.
				else
				{
					q.push(d);
					count++;
					sum += d;
					break;
				}
			}
		}
	}
	return count + bridge_length;
}

int main()
{
	int bridge_length = 2;
	int weight = 10;
	vector<int> v;
	v.push_back(7);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	int ans = solution(bridge_length, weight, v);
	printf("%d", ans);
}