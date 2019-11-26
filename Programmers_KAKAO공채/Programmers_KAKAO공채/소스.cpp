#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int solution(string s)
{
	if (s.size() == 1)
		return  1;
	int answer = 10001;
	int index = s.size() / 2;

	for (int x = index; x > 0; x--) //������� ���ϰ� �Ȱ���
	{
		string print = "";
		string compare = "";
		int count = 1;
		for(int i=0; i<s.size(); i+=x) //�� �κе� ����
		{ 
			string cur = s.substr(i, x);

			if (compare.empty()) //���� �ʱ�ȭ
			{
				compare = cur;
				continue;
			}
			
			if (compare != cur)
			{
				if (i + x >= s.size()) //�� ������ �ǹ��ϴ¹�
				{
					print += cur;
				}
				if (count > 1)
				{
					print += to_string(count) + compare;
				}
				else
				{
					print += compare;
				}
				compare = cur;
				count = 1;
			}
			else //compare == cur
			{
				count++;
				if (i + x >= s.size()) //�� ������ �ǹ��ϴ¹�
				{
					print += to_string(count) + cur; //�� �κ� ��������.
				}
			}
		}
		answer = min(answer, (int)print.size());
	}
	return answer;
}

int main()
{
	string s = "aabbaccc";
	int ans = solution(s);
	printf("%d", ans);
}