#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> ans;
	queue<int> q;
	int count = 0;
	
	//���� �ϼ� �ϼ��� ���ϴ� �ݺ���
	for (int i = 0; i < progresses.size(); ++i)
	{
		int day = 0;
		int cur = progresses.at(i);
		while (1)
		{
			if (cur >= 100)
			{
				q.push(day);
				break;
			}
			cur += speeds.at(i);
			++day;
		}
	}

	//ť���� ���� �� ��¥ �ϳ��� �̾Ƴ��� �̰ͺ��� ū ���ڰ� ���ö����� count�� ++��
	int cur = q.front();
	q.pop();
	++count;
	while (!q.empty())
	{
		if (cur >= q.front())
		{
			++count;
			q.pop();
		}
		else
		{
			ans.push_back(count);
			count = 0;
			cur = q.front();
			q.pop();
			++count;
		}
	}
	ans.push_back(count);
	return ans;
}

int main()
{
	vector<int> ans;
	vector<int> progress;
	vector<int> speed;
	progress.push_back(10);
	progress.push_back(1);

	speed.push_back(2);
	speed.push_back(1);

	ans = solution(progress, speed);
	for (int i = 0; i < ans.size(); ++i)
	{
		printf("%d ", ans.at(i));
	}
}