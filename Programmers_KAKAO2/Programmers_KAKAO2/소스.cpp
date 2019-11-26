#include <string>
#include <vector>
#include<iostream>
#include <cstdio>
using namespace std;
int arr[501] = { 0, }; //���̸� ������ �迭
int checkchar(string s)
{
	vector<char> v1;
	for (int i = 0; i < s.length(); ++i)
	{
		if (find(v1.begin(), v1.end(), s.at(i)) != v1.end()) continue;
		else v1.push_back(s.at(i));
	}
	return v1.size();
}

int solution(string s) {
	int answer = 0;

	int check = 0; //üũ�� ������ ����
	for (int i = 0; i < (s.length() / 2); ++i) //���ڿ� ���� ���� �ݺ�
	{
		int count = 0;
		check++; // 1���˻�, 2���˻�, 3���˻�, 4���˻�
		for (int i = 1; i < s.length(); i += check)
		{
			int num = check;
			if (i - 1 + num > s.length() || i - 1 > s.length()) break;
			string check_str = s.substr(i - 1, num);
			string original = s.substr(i - 1 + num, num);
			if (check_str == original)
				count++;
			
		}

		arr[i] = s.length() - (count * check);
		if (count != 0)
			arr[i] += count;
		if (count != 0 && check == 1)
		{
			arr[i] = s.length() - (count * check);
			arr[i] += checkchar(s);
		}

	}
	

	//���� ���� ���� ��ȯ�� for��
	answer = arr[0];
	for (int i = 0; i < (s.length() / 2) - 1; ++i)
		if (answer > arr[i + 1])
			answer = arr[i + 1];
	return answer;
}


int main()
{
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbb";
	int ans = solution(s);
	printf("%d", ans);
}