#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> q;
	priority_queue<int> pq;

	for (int i = 0; i < priorities.size(); i++) {
		// ť�� <ó�� ����� ����, �۾� �߿䵵> push
		q.push(make_pair(i, priorities[i]));
		// �켱���� ť�� �۾� �߿䵵 push(�ڵ������� �������� ������ �Ǿ� �񱳿����� ����)
		pq.push(priorities[i]);
	}

	while (!q.empty()) {
		// ���� �۾� ť�� front�� �켱���� ť�� �μ� �߿䵵�� ������ ���(��¼����� ���� ��)
		if (q.front().second == pq.top()) {
			// �������� ��û�� ������ȣ�� ���� �۾� ť�� front.first �� �ִ� ����� ������ ��ġ �� ���
			if (q.front().first == location) {
				return answer + 1;
			}
			else {
				// ����۾� �� �۾� ť�� �켱���� ť���� ������ �ϳ��� pop
				answer++;
				q.pop();
				pq.pop();
			}
		}
		else {
			// ��¼����� �ƴϹǷ� front�� �ִ� ���� ť�� �� �ڷ� �̵���Ű�� �۾�
			q.push(q.front());
			q.pop();
		}
	}
	return answer;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(9);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);

	int ans = solution(v, 0);
	printf("%d", ans);
}