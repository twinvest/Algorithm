#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> citations) {
	int index = 0;
	//�������� ���� 7 6 4 1 1 0���� ���ĵ�.
	sort(citations.begin(), citations.end(), greater<int>());
	
	//�񱳸� �ϴٰ� �ε����� �ش��ϴ� �迭 ���� �ε������� �۰ų� ������ �ش� �ε����� ����
	while (index < citations.size())
	{
		if (citations[index] <= index)
			break;
		index++;
	}
	return index;
}


int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(7);
	v.push_back(0);
	v.push_back(1);
	v.push_back(6);
	v.push_back(4);

	int ans = solution(v);
	printf("%d", ans);
}