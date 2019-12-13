#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int solution(vector<vector<int>> jobs) 
{
	int end = 0; int time = 0;

	vector<pair<int, int>> p;
	for (int i = 0; i < jobs.size(); ++i)
		p.push_back(make_pair(jobs[i][0], jobs[i][1]));

	sort(p.begin(), p.end(), compare);
	
	while (!p.empty())
	{
		for (int i = 0; i < p.size(); ++i)
		{
			if (p[i].first <= end)
			{
				end += p[i].second;  //end�� ���� ���μ����� ������ ������ ���� ������ �� �ִ� ���μ����� ���۵Ǵ� ��.
				//end���� ��ٸ� �ð�(��ٸ� �ð��� ��Ȯ�� ǥ���ϱ� ���� ��ȣ�� ħ)�� �����ְ� �װ��� time���� �ʱ�ȭ.
				//�� ��ٸ� �ð��� ������ �ɼ��� ������ �����غ���. �̺κ��� �����س��Ⱑ �ſ� �������. (0 3) (5 1)�϶� �׸��׷����� �����غ�~~ 6 + (3 -5) ==> ��� �̰ŋ����� level3�ε�
				time = end + (time - p[i].first);
				p.erase(p.begin() + i);
				break;
			}
			if (i == p.size() - 1) end++; //��� �ð��� end�� 1�� �÷���. (0 3) (5 1) �̷��� ���ö� 3���� �������� end�� 5���� �÷���� ù��° if������ ���԰���.
		}
	}
	return time / jobs.size();
}

int main()
{
	vector<vector<int>> v;

	vector<int> v1;
	v1.push_back(0);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(5);
	v2.push_back(1);

	vector<int> v3;
	v3.push_back(8);
	v3.push_back(2);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	int ans = solution(v);
	printf("%d", ans);
}