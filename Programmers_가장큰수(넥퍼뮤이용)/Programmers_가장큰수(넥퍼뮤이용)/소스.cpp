#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<int> numbers) {
	vector<string> s;
	vector<string> ans;

	//int�� string����
	for (int i = 0; i < numbers.size(); ++i)
		s.push_back(to_string(numbers[i]));
	
	//���۹¸� �̿��ؼ� ������ ������ ��� ans���Ϳ� �������.
	do
	{
		string tmp = "";
		for(int i = 0; i < numbers.size(); ++i)
			tmp += s[i];

		ans.push_back(tmp);
	} while (next_permutation(s.begin(), s.end()));
	
	//������������
	sort(ans.begin(), ans.end());
	return ans[ans.size() - 1];
}

int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(30);
	v.push_back(34);
	v.push_back(5);
	v.push_back(9);
	string ans = solution(v);
	cout << ans;
}